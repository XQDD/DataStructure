#include <iostream>
#include <valarray>
#include <cmath>
#include <bitset>
#include <ctime>
#include "../utils/main.cpp"
#include "IntSLList.h"
#include "genSkipL.h"

using namespace std;

//3.4 ��̬��Ծ����ָ��
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
    //������������ӣ���Ȼα���ÿ�����������������һ����
    srand(time(nullptr));

    cout << "���Ե�������" << endl;
    IntSLList l;

    l.addToTail(1);
    l.addToTail(2);
    l.addToTail(3);
    l.addToTail(4);
    l.addToTail(5);

    cout << l << endl;

    l.deleteNode(4);
    cout << l << endl;

    cout << "���Ա�׼����㼶" << endl;
    printSkipListPointer(10);

    cout << "����" << endl;
    SkipList<int> s;
    cout << "�������" << endl;
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

    cout << "����ṹ" << endl;
    cout << s;


}
