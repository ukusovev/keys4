#include <gtest/gtest.h>
#include "../src/queue.h"

TEST(QueueTest, EmptyQueue) {
    Queue<int> queue;
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, PushAndPop) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_EQ(queue.size(), 3);
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
    EXPECT_TRUE(queue.empty());
}

TEST(QueueTest, StringQueue) {
    Queue<std::string> queue;
    queue.push("test");
    queue.push("queue");
    
    EXPECT_EQ(queue.size(), 2);
    EXPECT_EQ(queue.pop(), "test");
    EXPECT_EQ(queue.pop(), "queue");
} 