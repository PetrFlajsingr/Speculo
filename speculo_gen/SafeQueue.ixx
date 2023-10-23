/**
* @file SafeQueue.h
* @brief A queue providing thread safe data passing between threads.
* @author Petr Flajšingr
* @date 7.4.18
*/

module;

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <optional>

export module speculo.gen:safe_queue;

namespace speculo::gen {
    /**
     * @brief A template queue to pass data between threads - thread safe
     */
    template<typename T>
    class SafeQueue {
    public:
        SafeQueue() : keep_running(true){};
        SafeQueue(SafeQueue &&other) noexcept : keep_running(std::exchange(other.keep_running, false)) {
            std::scoped_lock<std::mutex> lock(other.queueMutex);
            queue = std::move(other.queue);
        }
        SafeQueue &operator=(SafeQueue &&other) noexcept {
            if (this != &other) {
                std::scoped_lock<std::mutex, std::mutex> lock(queueMutex, other.queueMutex);
                queue = std::move(other.queue);
                keep_running = std::exchange(other.keep_running, false);
            }
            return *this;
        }
        /**
  * Add an item to the end of the queue
  * @param item item to be added
  */
        void enqueue(T item) {
            {
                std::lock_guard<std::mutex> lock(queueMutex);
                queue.push(std::forward<T>(item));
            }
            conditionVariable.notify_one();
        }

        [[nodiscard]] std::optional<T> dequeue() {
            std::unique_lock<std::mutex> lock(queueMutex);
            conditionVariable.wait(lock, [this] { return !queue.empty() || !keep_running; });

            if (!queue.empty()) {
                auto item = std::move(queue.front());
                queue.pop();
                return item;
            }
            return std::nullopt;
        }

        bool isEmpty() const {
            std::lock_guard<std::mutex> lock(queueMutex);
            return queue.empty();
        }

        void shutdown() {
            std::lock_guard<std::mutex> lock(queueMutex);
            keep_running = false;
            conditionVariable.notify_all();
        }

        [[nodiscard]] std::size_t size() const {
            std::lock_guard<std::mutex> lock(queueMutex);
            return queue.size();
        }

    private:
        mutable std::mutex queueMutex;
        std::condition_variable conditionVariable;
        std::queue<T> queue;
        std::atomic<bool> keep_running;
    };
}// namespace speculo::gen
