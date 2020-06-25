#include <iostream>
#include <valarray>
#include <cmath>
#include <bitset>
#include "../utils/main.cpp"
#include "IntSLList.h"

using namespace std;

//3.4 静态跳跃链表指向
void printSkipListPointer(int n)
{

    int maxK = floor(log2(n));

    for (int k = 1; k <= maxK; k++)
    {
        for (int i = 1; i <= (floor(n / (pow(2, k - 1)))) - 1; i++)
        {
            cout << "i=" << i << ",k=" << k << " ";
            cout << pow(2, k - 1) * i << "->" << pow(2, k - 1) * (i + 1) << endl;
        }
    }
}

int main()
{
    IntSLList l;

    l.addToTail(1);
    l.addToTail(2);
    l.addToTail(3);
    l.addToTail(4);
    l.addToTail(5);

    l.printAll();

    l.deleteNode(4);
    l.printAll();

    printSkipListPointer(30);
}
