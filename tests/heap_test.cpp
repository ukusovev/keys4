#include <gtest/gtest.h>
#include "../src/heap.h"

TEST(HeapTest, EmptyHeap) {
    Heap<int> heap;
    EXPECT_TRUE(heap.empty());
    EXPECT_EQ(heap.size(), 0);
}

TEST(HeapTest, PushAndPop) {
    Heap<int> heap;
    heap.push(3);
    heap.push(1);
    heap.push(2);
    
    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.pop(), 1);
    EXPECT_EQ(heap.pop(), 2);
    EXPECT_EQ(heap.pop(), 3);
    EXPECT_TRUE(heap.empty());
}

TEST(HeapTest, MaxHeap) {
    Heap<int, std::greater<int>> heap;
    heap.push(1);
    heap.push(3);
    heap.push(2);
    
    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.pop(), 3);
    EXPECT_EQ(heap.pop(), 2);
    EXPECT_EQ(heap.pop(), 1);
} 