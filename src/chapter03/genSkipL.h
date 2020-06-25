

#pragma once

const int maxLevel = 4;

template <typename T>
class SkipListNode
{
public:
    T key; //存储的数值
    SkipListNode **next; //指针数组
};

template <typename T>
class SkipList
{
public:
    SkipList();

    bool isEmpty() const;

    //初始化选择层级的下限，如1，9，13，15对应1，2，3，4层
    void choosePowers();

    //随机选择节点层级，因为要动态插入和删除节点，不可能按照定义来重新生成/维护跳跃链表
    int chooseLevel();

    T *skipListSearch(const T &);

    void skipListInsert(const T &);

private:
    typedef SkipListNode<T> *nodePtr;
    nodePtr root[maxLevel];
    int powers[maxLevel];
};