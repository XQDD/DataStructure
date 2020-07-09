/* ---------------------------------------------- */
/*        二叉搜索树(binary search tree)           */
/* ---------------------------------------------- */
#pragma once

#include <iostream>

using namespace std;

template<typename T>
class BSTNode {
public:
    BSTNode() {
        left = right = nullptr;
    }

    BSTNode(const T &e, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr) {
        el = e;
        left = l;
        right = r;
    }

    T el;
    BSTNode<T> *left, *right;
};


template<typename T>
class BST {
public:
    BST() {
        root = nullptr;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    T *search(BSTNode<T> *p, const T &el) const;

    void insert(const T &el);

protected:
    BSTNode<T> *root;

    virtual void visit(BSTNode<T> *p) {
        cout << p->el << ' ';
    }
};

template<typename T>
T *BST<T>::search(BSTNode<T> *p, const T &el) const {
    while (p != nullptr) {
        if (el == p->el) {
            return &p->el;
        } else if (el < p->el) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
}

template<typename T>
void BST<T>::insert(const T &el) {
    auto newNode = new BSTNode<T>(el);
    if (root == nullptr) {
        root = newNode;
    }
    auto *p = root;
    //缓存前面遍历过的节点，prev一定存在
    BSTNode<T> *prev = nullptr;
    //和查找一样的访问方式，但是一直遍历到叶子节点
    while (p != nullptr) {
        prev = p;
        if (el < p->el) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if (el < prev->el) {
        prev->left = newNode;
    } else {
        prev->right = newNode;
    }


}
