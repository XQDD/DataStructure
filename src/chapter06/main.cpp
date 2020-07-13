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
    cout << endl << "�������ṹ" << endl;
    PrintableTree print(&bst);

    cout << endl << "�������" << endl;
    bst.preOrder(bst.root);
    cout << endl << "�������" << endl;
    bst.inOrder(bst.root);
    cout << endl << "�������" << endl;
    bst.postOrder(bst.root);


}