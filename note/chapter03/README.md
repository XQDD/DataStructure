# 第3章

- [第3章](#第3章)
  - [3.4 跳跃链表(skip list)](#34-跳跃链表skip-list)

## 3.4 跳跃链表(skip list)

在有n个节点的跳跃链表中，对于每个满足$1{\le}k{\le}\lfloor{log_2n}\rfloor$和$1{\le}i{\le}\lfloor\frac{n}{2^{k-1}}\rfloor{-1}$，位于$2^{k-1}*i$的节点指向位于$2^{k-1}*(i+1)$的节点，含有$a$个指针的节点有$\frac{n}{2^a}$个，最大级数(层数)为maxLevel=$\lfloor{log_2n}\rfloor+1$

> $\lfloor{x}\rfloor$向下取整
