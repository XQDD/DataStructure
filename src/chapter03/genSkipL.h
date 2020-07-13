/* ---------------------------------------------- */
/*               跳跃链表(skip list)               */
/* ---------------------------------------------- */
#pragma once

#include <cmath>
#include "../utils/main.cpp"

const int maxLevel = 4;

template<typename T>
class SkipListNode {
public:
    T key;               //存储的数值
    SkipListNode *next[maxLevel] = {}; //指针数组，顺序存储当前层级所有节点
};

template<typename T>
class SkipList : public Printable {
public:
    SkipList();

    bool isEmpty() const;

    //初始化选择层级的下限，如1，9，13，15对应1，2，3，4层
    void choosePowers();

    //随机选择节点层级，0开始，因为要动态插入和删除节点，不可能按照定义来重新生成/维护跳跃链表
    int chooseLevel();

    T *skipListSearch(const T &);

    void skipListInsert(const T &);

    int length() const;


    void print() const override;

private:
    typedef SkipListNode<T> *nodePtr;
    nodePtr root[maxLevel];
    int powers[maxLevel];
};


template<typename T>
SkipList<T>::SkipList() {
    for (int i = 0; i < maxLevel; i++) {
        root[i] = nullptr;
    }
    choosePowers();
}

template<typename T>
bool SkipList<T>::isEmpty() const {
    return root[0] == nullptr;
}

template<typename T>
void SkipList<T>::choosePowers() {
    powers[maxLevel - 1] = pow(2, maxLevel - 1) - 1;
    for (int i = maxLevel - 2, j = 0; i >= 0; i--, j++) {
        powers[i] = powers[i + 1] - pow(2, j);
    }
}

template<typename T>
int SkipList<T>::chooseLevel() {
    int i, r = rand() % powers[maxLevel - 1] + 1;
    for (i = 1; i < maxLevel; i++) {
        if (r < powers[i]) {
            break;
        }
    }
    return i - 1;
}

template<typename T>
T *SkipList<T>::skipListSearch(const T &key) {
    if (isEmpty()) {
        return nullptr;
    }
    nodePtr prev, curr;
    //获取最高非空的层级
    int lvl;
    for (lvl = maxLevel - 1; lvl >= 0 && !root[lvl]; lvl--);
    //初始化前驱节点和当前节点
    prev = curr = root[lvl];
    while (true) {
        //若找到，直接返回值
        if (key == curr->key) {
            return &curr->key;
        }
            //当前节点值大于目标值
        else if (curr->key > key) {
            //已经是最后一层，未找到
            if (lvl == 0) {
                return nullptr;
            }
                //往下一层找
            else if (curr == root[lvl]) {
                //当前节点是根节点，则直接等于根节点的下一层
                curr = root[--lvl];
            } else {
                //当前节点非根节点，说明有前驱，则为前驱的后继的下一层
                curr = *(prev->next + (--lvl));
            }
        }
            //当前节点值小于目标值
        else {
            //记录前驱
            prev = curr;
            //当前层级还未遍历完，直接将当前节点置为往后一个节点
            if (*(curr->next + lvl) != nullptr) {
                curr = *(curr->next + lvl);
            } else {
                //向下一层级的后继找非空的节点
                for (lvl--; lvl >= 0 && *(curr->next + lvl) == nullptr; lvl--);
                //找到了，则将当前节点置为该节点
                if (lvl >= 0) {
                    curr = *(curr->next + lvl);
                }
                    //未找到，说明没有了，返回空指针
                else {
                    return nullptr;
                }
            }
        }
    }
}

template<typename T>
void SkipList<T>::skipListInsert(const T &key) {
    //当前遍历的节点
    nodePtr curr[maxLevel],
    ///当前遍历的节点的前驱
    prev[maxLevel];
    //当前遍历的层级
    int lvl;
    curr[maxLevel - 1] = root[maxLevel - 1];
    prev[maxLevel - 1] = nullptr;
    for (lvl = maxLevel - 1; lvl >= 0; lvl--) {
        //在同一层级中确定范围，prev用于缩小范围
        while (curr[lvl] && curr[lvl]->key < key) {
            prev[lvl] = curr[lvl];
            //+lvl的原因是curr[lvl]->next为第一层的节点，所以要加上lvl来访问当前层级的节点
            curr[lvl] = *(curr[lvl]->next + lvl);
        }
        //不能插入相同的元素
        if (curr[lvl] && curr[lvl]->key == key) {
            return;
        }
        //当前不是最底层，则向下一层遍历
        if (lvl != 0) {
            //前驱为空，则下一层前驱初始化为空，下一层当前节点为该层的根节点
            if (prev[lvl] == nullptr) {
                curr[lvl - 1] = root[lvl - 1];
                prev[lvl - 1] = nullptr;
            }
                //前驱不为空，则下一层前驱初始化为上一层的前驱，下一层的当前节点为当前层前驱的后继往下挪一层
            else {
                curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
                prev[lvl - 1] = prev[lvl];
            }
        }
    }

    //随机生成当前节点的层级
    lvl = chooseLevel();
    cout << "(" << key << "," << lvl + 1 << ") ";
    int i;
    //新节点
    nodePtr newNode = new SkipListNode<T>();
//    newNode->next = new nodePtr[sizeof(nodePtr) * (lvl + 1)];
    newNode->key = key;
    //将新节点置于每层遍历好的前驱与后继之间
    for (i = 0; i <= lvl; i++) {
        *(newNode->next + i) = curr[i];
        if (prev[i] == nullptr) {
            root[i] = newNode;
        } else {
            *(prev[i]->next + i) = newNode;
        }
    }
}

template<typename T>
int SkipList<T>::length() const {
    int len = 1;

    if (!isEmpty()) {
        auto temp = root[0];
        while (temp = *(temp->next)) {
            ++len;
        }
    }
    return len;
}


template<typename T>
void SkipList<T>::print() const {
    int len = length();

    if (len == 0) {
        return;
    }

    auto node = root;
    for (int i = 0; i < len; i++) {
        //当前节点值
        auto level1 = *(node);
        for (int j = 0; j < maxLevel; j++) {
            // node 为数组地址，数组地址+1等于当前地址加上数据类型长度，解引用则获取其中存储的值
            auto curr = *(node + j);
            if (curr != nullptr) {
                if (curr == level1) {
                    cout << curr->key << " ";
                }
            } else if (i != 0) {
                for (int k = j; k < maxLevel; k++) {
                    auto currK = root[k];
                    while (currK != nullptr) {
                        //低效率一层层一个个遍历比对是否为当前值
                        if (currK == level1) {
                            cout << currK->key << " ";
                            break;
                        }
                        currK = currK->next[k];
                    }
                }
                break;
            }
        }
        node = node[0]->next;
        cout << endl;
    }

}
