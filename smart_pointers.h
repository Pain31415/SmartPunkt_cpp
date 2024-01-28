#ifndef SMART_POINTERS_H
#define SMART_POINTERS_H

#include <iostream>

template<typename T>
class UniquePtr {
private:
    T* ptr;

public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}
    ~UniquePtr() { delete ptr; }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept : ptr(other.release()) {}
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        reset(other.release());
        return *this;
    }

    T* release() noexcept {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) noexcept {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }

    T& operator*() const noexcept { return *ptr; }
    T* operator->() const noexcept { return ptr; }
    T* get() const noexcept { return ptr; }

    explicit operator bool() const noexcept { return ptr != nullptr; }
};

template<typename T>
class SharedPtr {
private:
    T* ptr;
    size_t* ref_count;

public:
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new size_t(1)) {}
    ~SharedPtr() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*ref_count);
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    T& operator*() const noexcept { return *ptr; }
    T* operator->() const noexcept { return ptr; }
    T* get() const noexcept { return ptr; }

    size_t use_count() const noexcept { return *ref_count; }
};

#endif // SMART_POINTERS_H