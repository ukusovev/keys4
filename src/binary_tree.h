#pragma once

#include <cstddef>

template<typename T>
class BinaryTree {
public:
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
    };

    BinaryTree() : root(nullptr), tree_size(0) {}
    ~BinaryTree() { clear(root); }

    void push(const T& value) {
        root = insert(root, value);
        ++tree_size;
    }
    T pop() {
        T minVal{};
        root = removeMin(root, minVal);
        if (tree_size > 0) --tree_size;
        return minVal;
    }
    bool search(const T& value) const {
        return find(root, value);
    }
    bool empty() const { return tree_size == 0; }
    size_t size() const { return tree_size; }

private:
    Node* root;
    size_t tree_size;

    Node* insert(Node* node, const T& value) {
        if (!node) return new Node(value);
        if (value < node->value) node->left = insert(node->left, value);
        else node->right = insert(node->right, value);
        return node;
    }
    Node* removeMin(Node* node, T& minVal) {
        if (!node) return nullptr;
        if (!node->left) {
            minVal = node->value;
            Node* right = node->right;
            delete node;
            return right;
        }
        node->left = removeMin(node->left, minVal);
        return node;
    }
    bool find(Node* node, const T& value) const {
        if (!node) return false;
        if (node->value == value) return true;
        if (value < node->value) return find(node->left, value);
        return find(node->right, value);
    }
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
}; 