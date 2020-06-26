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

    void deleteNode(int);

    void printAll() const override;

private:
    IntSLLNode *head, *tail;
};