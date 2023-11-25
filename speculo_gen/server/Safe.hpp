#pragma once

#include <mutex>

namespace speculo::gen {

/**
 * @brief Wrapper class for safe access for objects which are not thread safe.
 * @tparam T protected type
 * @tparam Mutex mutex used for access locking
 */
    template<typename T, typename Mutex = std::mutex>
    class Safe final {
    public:
        /**
         * Type of access to data.
         */
        enum class AccessType { ReadWrite, ReadOnly };
        /**
         * @brief Object accessor providing locking.
         *
         * Upon creation this object locks Mutex and unlocks it when destroyed.
         */
        template<AccessType AccessPolicy = AccessType::ReadWrite>
        class Access;

    private:
        using ReadOnlyAccess = Access<AccessType::ReadOnly>;
        using ReadWriteAccess = Access<AccessType::ReadWrite>;

    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using pointer = T *;
        using const_pointer = const T *;

        /**
         * Inplace construction of protected value.
         * @tparam Args argument types for construction
         * @param args arguments forwarded to constructor
         */
        template<typename... Args>
        explicit Safe(Args &&...args) : value(std::forward<Args &&...>(args)...) {}
        /**
         * Inplace construction of protected value.
         * @tparam Args argument types for construction
         * @param mtx instance of mutex to be used for logging
         * @param args arguments forwarded to constructor
         */
        template<typename... Args>
        explicit Safe(Mutex &&mtx, Args &&...args) : mtx(std::move(mtx)), value(std::forward<Args &&...>(args)...) {}
        Safe(const Safe &other) : value(other.value), mtx(std::mutex{}) {}
        Safe &operator=(const Safe &other) {
            if (this == &other) { return *this; }
            value = other.value;
            mtx = std::mutex{};
            return *this;
        }
        Safe(Safe &&other) = delete;
        Safe &operator=(Safe &&other) = delete;

        /**
         * Get readwrite accessor to protected data.
         * @return readwrite accessor to protected data
         */
        ReadWriteAccess get() { return ReadWriteAccess{value, mtx}; }
        /**
         * Get readonly accessor to protected data.
         * @return readonly accessor to protected data
         */
        ReadOnlyAccess get() const { return ReadOnlyAccess{value, mtx}; }

        /**
         * Get readwrite accessor to protected data.
         * @return readwrite accessor to protected data
         */
        ReadWriteAccess writeAccess() { return ReadWriteAccess{value, mtx}; }
        /**
         * Get readonly accessor to protected data.
         * @return readonly accessor to protected data
         */
        ReadOnlyAccess readOnlyAccess() const { return ReadOnlyAccess{value, mtx}; }

        /**
         * Access inner data through an accessor with readwrite capabilities.
         * @return readwrite accessor to protected data
         */
        ReadWriteAccess operator->() { return get(); }
        /**
         * Access inner data through an accessor with readonly capabilities.
         * @return readonly accessor to protected data
         */
        ReadOnlyAccess operator->() const { return get(); }
        /**
         * Access inner data through an accessor with readwrite capabilities.
         * @return readwrite accessor to protected data
         */
        ReadWriteAccess operator*() { return get(); }
        /**
         * Access inner data through an accessor with readonly capabilities.
         * @return readonly accessor to protected data
         */
        ReadOnlyAccess operator*() const { return get(); }

        /**
         * Unsafe access to underlying value. Mutex is not locked.
         * @return reference to the underlying value
         */
        reference unsafe() { return value; }
        /**
         * Unsafe access to underlying value. Mutex is not locked.
         * @return const reference to the underlying value
         */
        const_reference unsafe() const { return value; }

        template<AccessType AccessPolicy>
        class Access final {
            using reference_type = std::conditional_t<AccessPolicy == Safe<T>::AccessType::ReadWrite, reference, const_reference>;
            using pointer_type = std::conditional_t<AccessPolicy == Safe<T>::AccessType::ReadWrite, pointer, const_pointer>;

        public:
            Access(reference_type value, Mutex &mtx) : value(value), lck(mtx) {}
            explicit Access(Safe<T, Mutex> &safe) : Access(safe.value, safe.mtx) {}
            Access(const Access &other) = delete;
            Access(Access &&other) = delete;
            Access &operator=(const Access &other) = delete;
            Access &operator=(Access &&other) = delete;

            reference_type operator*() noexcept { return value; }
            const_reference operator*() const noexcept { return value; }
            pointer_type operator->() noexcept { return &value; }
            const_pointer operator->() const noexcept { return &value; }

        private:
            reference_type value;
            std::unique_lock<Mutex> lck;
        };

    private:
        mutable Mutex mtx;
        value_type value;
    };

    template<typename T, typename Mutex = std::mutex>
    using ReadOnlyAccess = typename Safe<T, Mutex>::template Access<Safe<T, Mutex>::AccessType::ReadOnly>;

    template<typename T, typename Mutex = std::mutex>
    using WriteAccess = typename Safe<T, Mutex>::template Access<Safe<T, Mutex>::AccessType::ReadWrite>;
}// namespace pf