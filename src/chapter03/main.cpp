#include <iostream>
#include <valarray>
#include <cmath>
#include <bitset>
#include "../utils/main.cpp"
#include "IntSLList.h"
#include "genSkipL.h"

using namespace std;

//3.4 静态跳跃链表指向
void printSkipListPointer(int n) {

    int maxK = floor(log2(n));

    for (int k = 1; k <= maxK; k++) {
        for (int i = 1; i <= (floor(n / (pow(2, k - 1)))) - 1; i++) {
            cout << "i=" << i << ",k=" << k << " ";
            cout << pow(2, k - 1) * i << "->" << pow(2, k - 1) * (i + 1) << endl;
        }
    }
}

int main() {
    init();

    cout << "测试单向链表" << endl;
    IntSLList l;

    l.addToTail(1);
    l.addToTail(2);
    l.addToTail(3);
    l.addToTail(4);
    l.addToTail(5);
    cout << l << endl;


    cout << "单向链表翻转方法A" << endl;
    l.reverserByNewHead();
    cout << l << endl;
    cout << "单向链表翻转方法B" << endl;
    l.reverserInPlace();
    cout << l << endl;
    cout << "单向链表删除" << endl;
    l.deleteNode(4);
    cout << l << endl;

    cout << "======================" << endl;

    cout << "跳表" << endl;
    cout << "测试标准跳表层级" << endl;
    printSkipListPointer(10);

    SkipList<int> s;
    cout << "跳表插入" << endl;
    s.skipListInsert(1);
    s.skipListInsert(2);
    s.skipListInsert(8);
    s.skipListInsert(9);
    s.skipListInsert(3);
    s.skipListInsert(5);
    s.skipListInsert(4);
    s.skipListInsert(0);
    s.skipListInsert(6);
    s.skipListInsert(7);
    cout << endl;

    cout << "跳表结构" << endl;
    cout << s;


}

