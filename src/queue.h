#pragma once
#include <deque>

template<typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() = default;

    void push(const T& value) { data.push_back(value); }
    T pop() {
        if (data.empty()) return T();
        T val = data.front();
        data.pop_front();
        return val;
    }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }

private:
    std::deque<T> data;
}; 