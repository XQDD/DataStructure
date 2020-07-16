/* ---------------------------------------------- */
/*        二叉搜索树(binary search tree)           */
/* ---------------------------------------------- */
#pragma once

#include <iostream>
#include <queue>
#include <stack>
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

    virtual BSTNode<T> *getRoot() const;

    bool isEmpty() const {
        return root == nullptr;
    }

    //递归计算树的高度(层数)
    virtual int height(BSTNode<T> *node) const;

    //树的高度
    int height() const {
        return height(getRoot());
    }


    //查找
    T *search(BSTNode<T> *p, const T &el) const;

    //插入
    void insert(const T &el);

    //广度优先遍历(通过队列实现)
    void breadthFirst();

    //深度优先遍历
    //递归实现

    //中序遍历(对于二叉搜索树来说就是从小到大排列访问)
    void inOrder(BSTNode<T> *p);

    //先序遍历
    void preOrder(BSTNode<T> *p);

    //后序遍历
    void postOrder(BSTNode<T> *p);

    //循环实现

    //先序遍历
    void iterativePreOrder();

    //后序遍历
    void iterativePostOrder();

    //退化树(没有左节点，只有右节点)中序遍历(Morris算法)
    void morrisInOrder();


    //通过合并来删除节点，步骤1找到删除节点的位置
    void findAndDeleteByMerging(const T &el);

    //合并删除节点步骤2，通过指针引用实现节点替换功能
    void deleteByMerging(BSTNode<T> *&node);

    //通过复制来删除节点，步骤1与合并删除相同
    void findAndDeleteByCopy(const T &el);

    //复制删除节点步骤2
    void deleteByCopy(BSTNode<T> *&node);


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

template<typename T>
void BST<T>::iterativePreOrder() {
    stack<BSTNode<T> *> travStack;
    BSTNode<T> *p = root;
    if (p) {
        travStack.push(p);
        while (!travStack.empty()) {
            p = travStack.top();
            travStack.pop();
            visit(p);
            if (p->right) {
                travStack.push(p->right);
            }
            if (p->left) {
                travStack.push(p->left);
            }
        }
    }

}

template<typename T>
void BST<T>::iterativePostOrder() {
    stack<BSTNode<T> *> travStack;
    BSTNode<T> *p = root, *q = root;
    while (p) {
        while (p->left) {
            travStack.push(p);
            p = p->left;
        }
        while (!p->right || p->right == q) {
            visit(p);
            q = p;
            if (travStack.empty()) {
                return;
            }
            p = travStack.top();
            travStack.pop();
        }
        travStack.push(p);
        p = p->right;
    }


}

template<typename T>
BSTNode<T> *BST<T>::getRoot() const {
    return root;
}

template<typename T>
void BST<T>::morrisInOrder() {
    BSTNode<T> *p = root, *tmp;
    while (p) {
        //没有左节点，直接继续
        if (!p->left) {
            visit(p);
            p = p->right;
        } else {
            tmp = p->left;
            //访问最右边的节点，tmp->right != p目的是退化树已构造完毕，此时需要依次访问并切断节点，不能一直向右访问
            while (tmp->right && tmp->right != p) {
                tmp = tmp->right;
            }
            //1.链接节点，构造退化树
            if (!tmp->right) {
                tmp->right = p;
                p = p->left;
            }
                //2.访问退化树，切断节点
            else {
                visit(p);
                p = p->right;
                tmp->right = nullptr;
            }
        }
    }

}

template<typename T>
void BST<T>::findAndDeleteByMerging(const T &el) {
    BSTNode<T> *node = root, *prev;
    //先找到删除的节点
    while (node) {
        if (node->el == el) {
            break;
        }
        //记录父节点
        prev = node;
        if (node->el < el) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    //通过引用，达到无需知道其父节点，直接修改替换节点目的
    if (node && node->el == el) {
        if (node == root) {
            deleteByMerging(root);
        } else if (prev->left == node) {
            deleteByMerging(prev->left);
        } else {
            deleteByMerging(prev->right);
        }
    }
}

template<typename T>
void BST<T>::deleteByMerging(BSTNode<T> *&node) {
    if (node) {
        BSTNode<T> *tmp = node;
        //非同时有左右节点
        if (!node->right) {
            node = node->left;
        } else if (!node->left) {
            node = node->right;
        } else {
            //同时有左右节点，根据左子树总是小于右子树特性，将整个右子树放到左子树最右边(即该子树的最大值)的右边，反过来也行
            tmp = node->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            tmp->right = node->right;
            //记录原节点
            tmp = node;
            //节点替换(通过指针引用实现)
            node = node->left;
        }
        //删除节点
        delete tmp;
    }
}

template<typename T>
void BST<T>::findAndDeleteByCopy(const T &el) {
    BSTNode<T> *node = root, *prev;
    while (node) {
        if (node->el == el) {
            break;
        }
        prev = node;
        if (node->el < el) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    if (node && node->el == el) {
        if (node == root) {
            deleteByCopy(root);
        } else if (prev->left == node) {
            deleteByCopy(prev->left);
        } else {
            deleteByCopy(prev->right);
        }
    }
}

template<typename T>
void BST<T>::deleteByCopy(BSTNode<T> *&node) {
    if (node) {
        BSTNode<T> *tmp = node, *prev;
        if (!node->right) {
            node = node->left;
        } else if (!node->left) {
            node = node->right;
        } else {
            tmp = node->left;
            prev = node;
            while (tmp->right) {
                prev = tmp;
                tmp = tmp->right;
            }
            //复制左子树最右边的值到当前被删除的节点
            node->el = tmp->el;
            if (prev == node) {
                //左子树是单个叶子节点(即tmp)的情况,此时tmp->left值为nullptr,即直接删除左子树
                //等同于node->left=nullptr;
                prev->left = tmp->left;
            } else {
                //将左边上挪
                prev->right = tmp->left;
            }
        }
        //注意此时删除的是被复制的节点
        delete tmp;
    }
}
