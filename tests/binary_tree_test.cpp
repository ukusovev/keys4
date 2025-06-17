#include <gtest/gtest.h>
#include "../src/binary_tree.h"

TEST(BinaryTreeTest, EmptyTree) {
    BinaryTree<int> tree;
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
}

TEST(BinaryTreeTest, PushAndSearch) {
    BinaryTree<int> tree;
    tree.push(5);
    tree.push(3);
    tree.push(7);
    
    EXPECT_EQ(tree.size(), 3);
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.search(7));
    EXPECT_FALSE(tree.search(4));
}

TEST(BinaryTreeTest, Pop) {
    BinaryTree<int> tree;
    tree.push(5);
    tree.push(3);
    tree.push(7);
    
    EXPECT_EQ(tree.size(), 3);
    EXPECT_EQ(tree.pop(), 3);
    EXPECT_EQ(tree.size(), 2);
    EXPECT_FALSE(tree.search(3));
} 