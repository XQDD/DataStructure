#include <iostream>
#include <valarray>
#include <bitset>
#include "../utils/main.cpp"
#include "genBST.h"
#include "printableTree.h"
#include "genThreaded.h"

using namespace std;

int main() {
    init();

    BST<int> bst;
    bst.insert(6);
    bst.insert(8);
    bst.insert(7);
    bst.insert(3);
    bst.insert(1);
    bst.insert(9);
    println("二叉树结构");
    PrintableTree<int> print(&bst);
    println("合并删除");
    bst.findAndDeleteByMerging(6);
    print = PrintableTree<int>(&bst);


    println("递归");
    println("先序遍历");
    bst.preOrder(bst.root);
    println("中序遍历");
    bst.inOrder(bst.root);
    println("后序遍历");
    bst.postOrder(bst.root);

    println("循环");
    println("先序遍历");
    bst.iterativePreOrder();
    println("后序遍历");
    bst.iterativePostOrder();
    println("morris中序遍历");
    bst.morrisInOrder();

    println("线索树");
    ThreadedTree<int> threadedTree;
    threadedTree.insert(1);
    threadedTree.insert(3);
    threadedTree.insert(2);
    threadedTree.insert(4);
    print = PrintableTree<int>(&threadedTree, [](const BSTNode<int> *from, bool isLeft) {
        auto *t = (const ThreadedNode<int> *) from;
        return (BSTNode<int> *) (from ? (isLeft ? t->left : t->successor ? nullptr : t->right) : nullptr);
    });
    println("中序遍历");
    threadedTree.inOrder();

}