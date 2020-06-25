#include "IntSLList.h"

#include <iostream>

using namespace std;

void IntSLList::addToTail(int el)
{
    if (tail != nullptr)
    {
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    }
    else
    {
        head = tail = new IntSLLNode(el);
    }
}

void IntSLList::deleteNode(int el)
{
    if (head != nullptr)
    {
        if (head == tail && el == head->info)
        {
            delete head;
            head = tail = nullptr;
        }
        else if (el == head->info)
        {
            IntSLLNode *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            IntSLLNode *pred, *temp;
            for (pred = head, temp = pred->next;
                 temp != nullptr;
                 pred = pred->next, temp = temp->next)
            {
                if (temp->info == el)
                {
                    pred->next = temp->next;
                    if (temp == tail)
                    {
                        tail = pred;
                    }
                    delete temp;
                }
            }
        }
    }
}

void IntSLList::printAll()
{
    auto temp = head;
    while (temp != nullptr)
    {
        cout << temp->info << ", ";
        temp = temp->next;
    }
    cout << endl;
}