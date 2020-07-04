#include "IntSLList.h"

#include <iostream>

using namespace std;

void IntSLList::addToTail(int el) {
    if (tail != nullptr) {
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    } else {
        head = tail = new IntSLLNode(el);
    }
}

void IntSLList::deleteNode(int el) {
    if (head != nullptr) {
        if (head == tail && el == head->info) {
            delete head;
            head = tail = nullptr;
        } else if (el == head->info) {
            IntSLLNode *temp = head;
            head = head->next;
            delete temp;
        } else {
            IntSLLNode *pred, *temp;
            for (pred = head, temp = pred->next;
                 temp != nullptr;
                 pred = pred->next, temp = pred->next) {
                if (temp->info == el) {
                    pred->next = temp->next;
                    if (temp == tail) {
                        tail = pred;
                    }
                    delete temp;
                }
            }
        }
    }
}

void IntSLList::printAll() const {
    auto temp = head;
    while (temp != nullptr) {
        cout << temp->info << ", ";
        temp = temp->next;
    }
}

void IntSLList::reverserByNewHead() {
    if (!head) {
        return;
    }
    //初始化
    auto newHead = head;
    auto curr = head->next;
    newHead->next = nullptr;
    while (curr) {
        auto tempNext = curr->next;
        //一步一步往新链表从后面到前面加节点，过程为
        // 0
        // 1
        // 2 1
        // 3 2 1
        curr->next = newHead;
        newHead = curr;
        curr = tempNext;
    }
    head = newHead;
}

void IntSLList::reverserInPlace() {
    if (!head) {
        return;
    }
    //初始化
    auto tempHead = new IntSLLNode();
    tempHead->next = head;
    auto curr = head;
    while (auto next = curr->next) {
        //过程，curr值不变，但是next在变
        //0 1 2 3 4
        //0 2 1 3 4
        //0 3 2 1 4
        //0 4 3 2 1
        auto temp = next->next;
        next->next = tempHead->next;
        tempHead->next = next;
        curr->next = temp;
    }
    head = tempHead->next;
}
