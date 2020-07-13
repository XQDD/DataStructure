#include <iostream>
#include <valarray>
#include <bitset>
#include "../utils/main.cpp"
#include "genBST.h"
#include "printableTree.h"

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
    cout << endl << "二叉树结构" << endl;
    PrintableTree print(&bst);

    cout << endl << "先序遍历" << endl;
    bst.preOrder(bst.root);
    cout << endl << "中序遍历" << endl;
    bst.inOrder(bst.root);
    cout << endl << "后序遍历" << endl;
    bst.postOrder(bst.root);


}