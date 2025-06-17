#pragma once
#include <vector>
#include <algorithm>
#include <functional>

template<typename T, typename Compare = std::less<T>>
class Heap {
public:
    Heap() = default;
    ~Heap() = default;

    void push(const T& value) {
        data.push_back(value);
        std::push_heap(data.begin(), data.end(), comp);
    }
    T pop() {
        if (data.empty()) return T();
        std::pop_heap(data.begin(), data.end(), comp);
        T val = data.back();
        data.pop_back();
        return val;
    }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }

private:
    std::vector<T> data;
    Compare comp;
}; 