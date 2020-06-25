#include "genSkipL.h"
#include <cmath>

template <typename T>
SkipList<T>::SkipList()
{
    for (int i = 0; i < maxLevel; i++)
    {
        root[i] = nullptr;
    }
}

template <typename T>
bool SkipList<T>::isEmpty() const
{
    return root[0] == nullptr;
}

template <typename T>
void SkipList<T>::choosePowers()
{
    powers[maxLevel - 1] = pow(2, maxLevel - 1) - 1;
    for (int i = maxLevel - 2, j = 0; i >= 0; i--, j++)
    {
        powers[i] = powers[i + 1] - pow(2, j);
    }
}

template <typename T>
int SkipList<T>::chooseLevel()
{
    int i, r = rand() % powers[maxLevel - 1] + 1;
    for (int i = 1; i < maxLevel; i++)
    {
        if (r < powers[i])
        {
            break;
        }
    }
    return i - 1;
}

template <typename T>
T *SkipList<T>::skipListSearch(const T &key)
{
    if (isEmpty())
    {
        return nullptr;
    }
    nodePtr prev, curr;
    //获取最高非空的层级
    int lvl;
    for (lvl = maxLevel - 1; lvl >= 0 && !root[lvl]; lvl--)
        ;
    //初始化前驱节点和当前节点
    prev = curr = root(lvl);
    while (true)
    {
        //若找到，直接返回值
        if (key == curr->key)
        {
            return &curr->key;
        }
        //当前节点值大于目标值
        // TODO
        else if (key < curr->key)
        {
            if (lvl == 0)
            {
                return nullptr;
            }
            else if (curr == root[lvl])
            {
                curr == root[--lvl];
            }
            else
            {
                curr = *(prev->next + (--lvl));
            }
        }
        //当前节点值小于目标值
        else
        {
            prev = curr;
            if (*(curr->next + lvl) != 0)
            {
                curr = *(curr->next + lvl);
            }
            else
            {
                for (lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--)
                {
                    if (lvl >= 0)
                    {
                        curr = *(curr->next + lvl);
                    }
                    else
                    {
                        return nullptr;
                    }
                }
            }
        }
    }
}

template <typename T>
void SkipList<T>::skipListInsert(const T &key)
{
    nodePtr curr[maxLevel], prev[maxLevel], newNode;
    int lvl, i;
    curr[maxLevel - 1] = root[maxLevel - 1];
}
