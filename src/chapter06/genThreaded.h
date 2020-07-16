/* ---------------------------------------------- */
/*                线索树                          */
/* ---------------------------------------------- */
#pragma once

#include "genBST.h"

template<typename T>
class ThreadedNode : public BSTNode<T> {
public:
    ThreadedNode() : BSTNode<T>() {}

    ThreadedNode(const T &e, ThreadedNode *l = nullptr, ThreadedNode *r = nullptr) : BSTNode<T>(e, l, r),
                                                                                     successor(false) {}

    bool successor;
    ThreadedNode<T> *left, *right;
};

template<typename T>
class ThreadedTree : public BST<T> {
public:
    ThreadedNode<T> *root;

    BSTNode<T> *getRoot() const override;

    ThreadedTree() {
        root = nullptr;
    }

    void insert(const T &);

    void inOrder();

    int height(BSTNode<T> *node) const override;

};

template<typename T>
void ThreadedTree<T>::insert(const T &el) {
    ThreadedNode<T> *p, *prev = nullptr, *newNode;
    newNode = new ThreadedNode<T>(el);
    if (!root) {
        root = newNode;
        return;
    }
    p = root;
    //遍历到需要插入节点的位置
    while (p) {
        prev = p;
        if (p->el > el) {
            p = p->left;
        } else if (!p->successor) {
            p = p->right;
        } else {
            break;
        }
    }

    //插入节点
    //1.新节点小于prev，放在左边，则prev为其后继
    if (prev->el > el) {
        prev->left = newNode;
        newNode->successor = true;
        newNode->right = prev;
    }
        //2.prev有后继，并且此时新节点大于prev，则放在其右边，并将其后继替换
    else if (prev->successor) {
        newNode->successor = true;
        prev->successor = false;
        newNode->right = prev->right;
        prev->right = newNode;
    }
        //3.prev为最右边节点，直接放在右边
    else {
        prev->right = newNode;
    }

}

template<typename T>
void ThreadedTree<T>::inOrder() {
    ThreadedNode<T> *prev, *p = root;
    if (p) {
        //访问最左边的
        while (p->left) {
            p = p->left;
        }
        while (p) {
            BST<T>::visit(p);
            prev = p;
            //向右访问
            p = p->right;
            //prev不是successor的时候一直向左访问
            if (p && !prev->successor) {
                while (p->left) {
                    p = p->left;
                }
            }
        }
    }
}

template<typename T>
BSTNode<T> *ThreadedTree<T>::getRoot() const {
    return this->root;
}

template<typename T>
int ThreadedTree<T>::height(BSTNode<T> *node) const {
    ThreadedNode<T> *t = (ThreadedNode<T> *) node;
    return t == nullptr || t->successor ? 0 : (1 + max(height(t->left), height(t->right)));
}

