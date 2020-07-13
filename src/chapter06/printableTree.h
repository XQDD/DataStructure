#pragma once

#include <string>
#include <iostream>
#include "../utils/main.cpp"
#include "genBST.h"

const string delimiter = "=";

class PrintableTreeNodeType : public Printable {
public:
    string value = delimiter;
    int totalLength;
    bool rightmost = false;

    void print() const override {
        int leftLength = totalLength / 2 - value.length() / 2;
        int rightLength = totalLength - leftLength - value.length();
        if (leftLength > rightLength) {
            int temp = leftLength;
            leftLength = rightLength;
            rightLength = temp;
        }

        while (leftLength-- > 0) {
            cout << delimiter;
        }
        cout << value;
        while (rightLength-- > 0) {
            cout << delimiter;
        }

        if (rightmost) {
            cout << endl;
        }
    }
};

typedef BSTNode<PrintableTreeNodeType> PrintableTreeNode;


template<typename T>
class PrintableTree : public BST<PrintableTreeNodeType> {
public:
    PrintableTree(const BST<T> *from) {
        //转为完全二叉树
        //计算每个节点需要打印的总长度(包括空格)
        if (from->root) {
            root = new PrintableTreeNode;
            copy(from->root, root, from->height());
        }
        //广度优先遍历打印结果
        breadthFirst();
    }

private:
    int copy(BSTNode<T> *from, PrintableTreeNode *node, int totalLevel, int currLevel = 1,
             bool rightmost = true) {
        if (from) {
            node->el.value = toString(from->el);
        }
        node->el.rightmost = rightmost;
        int nodeLength;
        if (currLevel < totalLevel) {
            node->left = new PrintableTreeNode;
            node->right = new PrintableTreeNode;
            int leftLength = copy(from ? from->left : nullptr, node->left, totalLevel, currLevel + 1, false);
            int rightLength = copy(from ? from->right : nullptr, node->right, totalLevel, currLevel + 1,
                                   rightmost);
            nodeLength = leftLength + rightLength;
        } else {
            nodeLength = node->el.value.length();
            if (!rightmost) {
                nodeLength += 1;
            }
        }
        node->el.totalLength = nodeLength;
        return nodeLength;
    }

    void visit(BSTNode<PrintableTreeNodeType> *p) override {
        cout << p->el;
    }

};
