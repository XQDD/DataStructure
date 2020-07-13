/* ---------------------------------------------- */
/*        二叉搜索树(binary search tree)           */
/* ---------------------------------------------- */
#pragma once

#include <iostream>
#include <queue>
#include <cmath>

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

protected:
    virtual void visit(BSTNode<T> *p) {
        cout << p->el << ' ';
    }

public:
    BSTNode<T> *root;

    BST() {
        root = nullptr;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    //递归计算树的高度(层数)
    int height(BSTNode<T> *node) const;

    //树的高度
    int height() const {
        return height(root);
    }


    //查找
    T *search(BSTNode<T> *p, const T &el) const;

    //插入
    void insert(const T &el);

    //广度优先遍历(通过队列实现)
    void breadthFirst();

    //深度优先遍历
    //递归实现
    //中序遍历
    void inOrder(BSTNode<T> *p);

    //先序遍历
    void preOrder(BSTNode<T> *p);

    //后序遍历
    void postOrder(BSTNode<T> *p);

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
    auto *newNode = new BSTNode<T>(el);
    if (root == nullptr) {
        root = newNode;
        return;
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

template<typename T>
void BST<T>::breadthFirst() {
    queue<BSTNode<T> *> itQueue;
    auto *p = root;
    if (p != nullptr) {
        itQueue.push(p);
        while (!itQueue.empty()) {
            p = itQueue.front();
            itQueue.pop();
            visit(p);
            if (p->left != nullptr) {
                itQueue.push(p->left);
            }
            if (p->right != nullptr) {
                itQueue.push(p->right);
            }
        }
    }
}

template<typename T>
int BST<T>::height(BSTNode<T> *node) const {
    return node == nullptr ? 0 : (1 + max(height(node->left), height(node->right)));
}


template<typename T>
void BST<T>::inOrder(BSTNode<T> *p) {
    if (p) {
        inOrder(p->left);
        visit(p);
        inOrder(p->right);
    }
}

template<typename T>
void BST<T>::preOrder(BSTNode<T> *p) {
    if (p) {
        visit(p);
        preOrder(p->left);
        preOrder(p->right);
    }
}

template<typename T>
void BST<T>::postOrder(BSTNode<T> *p) {
    if (p) {
        postOrder(p->left);
        postOrder(p->right);
        visit(p);
    }
}