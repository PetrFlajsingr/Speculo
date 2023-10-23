module;

#include <algorithm>
#include <concepts>
#include <functional>
#include <future>
#include <ranges>
#include <thread>

export module speculo.gen:thread_pool;
import :safe_queue;

namespace speculo::gen {
    namespace details {
        struct Task {
            void operator()() { execute(); }
            virtual void execute() = 0;

            virtual ~Task() = default;
        };

        template<typename T>
        struct PTask : public Task {
            explicit PTask(std::packaged_task<T()> &&pTask) : task(std::move(pTask)) {}
            void execute() override { task(); }
            std::packaged_task<T()> task;
        };
    }// namespace details

    enum class ThreadPoolState { Run, Stop, FinishAndStop };

    /**
     * @brief A thread pool running queued tasks in threads.
     */
    export class ThreadPool {
    public:
        /**
  * Construct ThreadPool.
  * @param threadCount count of threads handling tasks
  */
        explicit ThreadPool(std::size_t threadCount) {
            threads.resize(threadCount);
            std::ranges::generate(threads.begin(), threads.end(), [this] { return std::thread{[this] { threadLoop(); }}; });
        }
        ThreadPool(const ThreadPool &) = delete;
        ThreadPool &operator=(const ThreadPool &) = delete;
        ThreadPool(ThreadPool &&) = default;
        ThreadPool &operator=(ThreadPool &&) = default;

        /**
         * Enqueue a task to be executed when possible.
         * @param callable task to be run
         * @return future, resolved when task is finished
         */
        auto enqueue(std::invocable auto &&callable) {
            using result_type = std::invoke_result_t<decltype(callable)>;
            auto task = std::packaged_task<result_type()>(std::forward<decltype(callable)>(callable));
            auto future = task.get_future();
            queue.enqueue(std::make_unique<details::PTask<result_type>>(std::move(task)));
            return future;
        }

        /**
  * Finish remaining tasks and stop.
  */
        void finishAndStop() { state = ThreadPoolState::FinishAndStop; }
        /**
  * Clear remaining tasks and stop.
  */
        void cancelAndStop() {
            state = ThreadPoolState::Stop;
            queue.shutdown();
        }

        ~ThreadPool() {
            if (state == ThreadPoolState::Run) { state = ThreadPoolState::FinishAndStop; }
            queue.shutdown();
            if (state == ThreadPoolState::FinishAndStop) {
                while (!queue.isEmpty()) {};
            }
            for (auto &thread: threads) { thread.join(); }
        }

    private:
        std::vector<std::thread> threads;
        SafeQueue<std::unique_ptr<details::Task>> queue;
        ThreadPoolState state = ThreadPoolState::Run;

        void threadLoop() {
            while (true) {
                auto task = queue.dequeue();
                if (task.has_value()) {
                    auto callable = std::move(task.value());
                    (*callable)();
                } else {
                    return;
                }
            }
        }
    };
}// namespace speculo::gen
