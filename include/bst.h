// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>

template<typename T>

class BST {
 private:
    struct Node {
        Node* right;
        Node* left;
        T value;
        int k;
    };
    Node* root;
    Node* add_Node(Node* root, T value) {
        if (!root) {
            root = new Node;
            root->value = value;
            root->k = 1;
            root->right = nullptr;
            root->left = nullptr;
        } else if (root->value > value) {
            root->left = add_Node(root->left, value);
        } else if (root->value < value) {
            root->right = add_Node(root->right, value);
        } else {
            ++root->k;
        }
        return root;
    }
    int Search(Node* root, T value) {
        int a = 0;
        if (root->value == value) {
            a = root->k;
        } else if (root->value > value) {
            a = Search(root->left, value);
        } else if (root->value < value) {
            a = Search(root->right, value);
        }
        return a;
    }
  
    int Depth(Node* root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(Depth(root->left), Depth(root->right));
    }

 public:
    BST():root(nullptr) {}
    void add(T value) {
        root = add_Node(root, value);
    }
    int search(T value) {
        return Search(root, value);
    }
    int depth() {
        return Depth(root) - 1;
    }
};

#endif  // INCLUDE_BST_H_
