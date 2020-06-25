/* -------------------------------------------------------------------------- */
/*                                    单向链表                                    */
/* -------------------------------------------------------------------------- */
#pragma once

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

class IntSLList
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

    void printAll();

private:
    IntSLLNode *head, *tail;
};