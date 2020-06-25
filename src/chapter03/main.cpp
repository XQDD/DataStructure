#include <iostream>
#include <valarray>
#include <bitset>
#include "../utils/main.cpp"
#include "IntSLList.h"

using namespace std;

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
}