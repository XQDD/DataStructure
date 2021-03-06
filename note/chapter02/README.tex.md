# 第2章

- [第2章](#第2章)
  - [1. 大$O$表示法](#1-大math-xmlnshttpwwww3org1998mathmathmlsemanticsmrowmiomimrowannotation-encodingapplicationx-texoannotationsemanticsmatho表示法)
    - [定义1](#定义1)
      - [性质](#性质)
        - [性质1](#性质1)
        - [性质2](#性质2)
        - [性质3](#性质3)
        - [性质4](#性质4)
        - [性质5](#性质5)
        - [性质6](#性质6)
        - [性质7](#性质7)
  - [2. $\Omega$表示法与$\Theta$表示法](#2-math-xmlnshttpwwww3org1998mathmathmlsemanticsmrowmi-mathvariantnormalωmimrowannotation-encodingapplicationx-texomegaannotationsemanticsmathω表示法与math-xmlnshttpwwww3org1998mathmathmlsemanticsmrowmi-mathvariantnormalθmimrowannotation-encodingapplicationx-texthetaannotationsemanticsmathθ表示法)
    - [定义2](#定义2)
    - [定义3](#定义3)
  - [3. 平均复杂度](#3-平均复杂度)

## 1. 大$O$表示法

### 定义1

如果**存在**正数$c$和$N$，对所有的$n{\ge}{N}$，有$f(n){\le}cg(n)$，则$f(n)=O(g(n))$

> 把$cg(n)$放到不等式右边易于理解，即此函数为原函数的上界

#### 性质

##### 性质1

(传递性)如果$f(n)=O(g(n))$，$g(n)=O(h(n))$，那么$f(n)=O(h(n))$(也可表述为$O(O(g(n)))=O(g(n))$)

##### 性质2

如果$f(n)=O(h(n))$，$g(n)=O(h(n))$，则$f(n)+g(n)=O(h(n))$

##### 性质3

$an^k=O(n^k)$

##### 性质4

对于任何正数$j$，$n^k=O(n^{k+j})$

- 令$c=N=1$，该性质成立

> 结合性质2,3,4可以推出，任何多项式都是该多项式中次数最高的项的大O表示，即  
> $f(n)=a_kn^k+a_{k-1}n^{k-1}+...+a_1n+a_0=O(n^k)$

##### 性质5

如果$f(n)=cg(n)$，则$f(n)=O(g(n))$

##### 性质6

对于任意正数$a$和$b(b{\ne}1)$，$log_an=O(log_bn)$

##### 性质7

对于任何正数$a{\ne}1，log_an=O(lgn)$，其中$lgn=log_2n$

## 2. $\Omega$表示法与$\Theta$表示法

### 定义2

若存在正数$c$和$N$，对于所有的$n{\ge}N$，有$f(n){\ge}cg(n)$，则$f(n)=\Omega(g(n))$

> 把$cg(n)$放到不等式右边易于理解，即此函数为原函数的下界

### 定义3

若存在正数$c_1、c_2$及$N$，对于所有的$n{\ge}N$，有$c_1g(n){\le}f(n){\le}c_2g(n)$，则$f(n)=\Theta(g(n))$

## 3. 平均复杂度

$C_{avg}=\sum_ip(input_t)steps(input_i)$
