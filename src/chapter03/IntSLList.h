/* -------------------------------------------------------------------------- */
/*                                    单向链表                                    */
/* -------------------------------------------------------------------------- */
#pragma once

#include "../utils/main.cpp"

class IntSLLNode
{
public:
    IntSLLNode()
    {
        next = nullptr;
    }

    IntSLLNode(int el, IntSLLNode *ptr = nullptr)
    {
        info = el;
        next = ptr;
    }

    int info;
    IntSLLNode *next;
};

class IntSLList : public Printable
{
public:
    IntSLList()
    {
        head = tail = nullptr;
    }
    int isEmpty()
    {
        return head == nullptr;
    }

    void addToTail(int);

    //3.10 P113 单链表翻转
    //通过头节点构建新链表翻转法
    void reverserByNewHead();
    //就地翻转法
    void reverserInPlace();


    void deleteNode(int);

    void printAll() const override;

private:
    IntSLLNode *head, *tail;
};