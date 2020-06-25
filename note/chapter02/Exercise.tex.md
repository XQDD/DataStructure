
# 2.11 习题

- [2.11 习题](#211-习题)
  - [1](#1)
    - [1.a](#1a)
    - [1.b](#1b)
  - [2](#2)
    - [2.a](#2a)
    - [2.b](#2b)
    - [2.c](#2c)
    - [2.d](#2d)
    - [2.e](#2e)
  - [3](#3)
    - [3.a](#3a)
    - [3.b](#3b)
    - [3.c](#3c)
    - [3.d](#3d)
    - [3.e](#3e)
    - [3.f](#3f)
    - [3.g](#3g)
  - [4](#4)
    - [4.a](#4a)
  - [5](#5)
  - [6](#6)
    - [6.a](#6a)
    - [6.b](#6b)
    - [6.c](#6c)
  - [7](#7)
  - [8](#8)
  - [9](#9)
  - [10](#10)
    - [10.a](#10a)
    - [10.b](#10b)
    - [10.c](#10c)
    - [10.d](#10d)
  - [11](#11)
  - [12](#12)
  - [13](#13)

## 1

### 1.a

$f(n)$的上界为常数$c$

### 1.b

$f(n)$为常函数,$c$为它确定的函数轮廓

> c. $f(n)$的上界为$n$的常数次方

## 2

$f_1(n)=O(g_1(n))$的定义：存在正数$c_1$和$N_1$，对于$n{\ge}N_1$，都有$f_1(n){\le}c_1g_1(n)$

$f_2(n)=O(g_2(n))$的定义：存在正数$c_2$和$N_2$，对于$n{\ge}N_2$，都有$f_2(n){\le}c_2g_2(n)$

### 2.a

由定义可得，对于所有$n\ge\max(N_1,N_2)$

$f_1(n){\le}c_1\max(g_1(n),g_2(n))$

$f_2(n){\le}c_2\max(g_1(n),g_2(n))$

得$f_1(n)+f_2(n)\le(c_1+c_2)\max(g_1(n),g_2(n))$

则对于$c_3=c_1+c_2$和$N_3=\max(N_1,N_2)$，有$f_1(n)+f_2(n){\le}c_3\max(g_1(n),g_2(n))$

即$f_1(n)+f_2(n)=O(\max(g_1(n),g_2(n)))$得证

### 2.b

使$c=\max(c_1,c_2)$

则$cg_1(n){\le}cg_2(n)$

有$cg_1(n)+cg_2(n){\le}2cg_2(n)$，即$O(g_1(n)+g_2(n))=O(g_2(n))$

### 2.c

设$c=c_1*c_2$，则$O(g_1(n)*g_2(n))=c_1*c_2g_1(n)*g_2(n)=cg_1(n)*g_2(n){\ge}f_1(n)*f_2(n)$

### 2.d

$O(cg(n))=cc_1g(n)$，令$c_2=cc_1$，因为$O(g(n))=c_2g_(n)$，则得证

### 2.e

设$c{\le}c_1$，因为$O(1)=c_1*1$，所以$c=O(1)$

## 3

### 3.a

因为$n>1$，令$c=1$

$\sum_{i=1}^ni^2=\frac{2n^3+3n^2+n}{6}{\le}\frac{2n^3+3n^2*n+n*n^2}{6}=cn^3=O(n^3)$

通常，$\sum_{i=1}^ni^k=O(n^{k+1})$，
**此处留给大神证明*

### 3.b

设$\frac{an^k}{log_2n}=O(n^k){\le}cn^k$

则$\frac{a}{log_2n}{\le}c$

当$N{\ge}2$时，$log_2n{\ge}1$，则$\frac{a}{log_2n}{\le}1$，此时令$c=1$得证

但是$\because n\to\infin，\therefore log_2n\to\infin，\frac{a}{log_2n}\to0$，则无论$c$取何值，都不能使得$\frac{a}{log_2n}{\ge}c$恒成立(注意$c$为负数的时候，也可以让$a$为负数)，所以$\frac{an^k}{log_2n}{\ne}\Theta(n^k)$

### 3.c

若想$n^{1.1}+nlog_2n=\Theta(n^{1.1})$成立

则需要$c_1n^{1.1}{\le}n^{1.1}+nlog_2n{\le}c_2n^{1.1}$

即$c_1{\le}1+\frac{log_2n}{n^{0.1}}{\le}c_2$ ①

根据
> $(log_ax)'=alnx$  
> $(x^a)'=ax^{a-1}$  
> 无穷比无穷型洛必达法则 $\lim_{x{\to}a}\frac{f(x)}{g(x)}=\lim_{x{\to}a}\frac{f'(x)}{g'(x)}$  
> <https://baike.baidu.com/item/%E6%B4%9B%E5%BF%85%E8%BE%BE%E6%B3%95%E5%88%99/7646700?fr=aladdin>

得$\frac{log_2n}{n^{0.1}}=\frac{0.1}{n^{0.1}ln2}$

取$c_1=0，c_2=\frac{0.1}{ln2}$满足不等式①，得证

### 3.d

设$2^n{\le}cn!$，则$c{\ge}\frac{2^n}{n!}$，$\because\frac{2^n}{n!}=\frac{2}{1}*\frac{2}{2}*\frac{2}{3}...*\frac{2}{n}{\le}2，{\therefore}c{\ge}2$时不等式成立

设$n!{\le}c2^n$，则$c{\ge}\frac{n!}{2^n}$，$\because\frac{n!}{2^n}=\frac{1}{2}*\frac{2}{2}*\frac{3}{2}...*\frac{n}{2}{\ge}\to\infin，{\therefore}$不存在常数$c$使得不等式成立

### 3.e

设存在常数$c$使得$2^{n+a}{\le}c2^n$，得$c{\ge}2^a$，则得证

### 3.f

设存在常数$c$使得$2^{2n+a}{\le}c2^n$，得$c{\ge}2^{n+a}$，但不存在满足该不等式得常量$c$，则得证

### 3.g

$由n=2^{log_2n}$可以推出在$a>0$时等式成立，**但是$a{\le}0$时暂不清楚如何证明*

## 4

### 4.a

令$f_1(n)=a_1n，f_2(n)=a_2n$，此时$g_1(n)=n，g_2(n)=n$，则$f_1(n)-f_2(n)=(a_1-a_2)n{\ne}O(n-n)=O(0)$

令$f_1(n)=a_1n，f_2(n)=a_2n^2$，$a_1>0，a_2>0$，此时$g_1(n)=n，g_2(n)=n^2$，则$\frac{f_1(n)}{f_2(n)}=\frac{a_1}{a_2n}=O(1){\ne}O(\frac{n}{n^2})=O(\frac{1}{n})$

## 5

$f_1(n)=n^2=O(n^2)$

$f_2(n)=n=O(n)$

$g(n)=n^2$

$f_1{\ne}O(f_2)=O(n)$

## 6

### 6.a

false，$f(n)为n，gn为2n时$

### 6.b

false，$f(n)为n^2，gn为n时$

### 6.c

false，当$a>2$时，找不到常数$c$使不等式$c{\ge}2^{n(a-1)}$成立

## 7

数组为倒序时

## 8

$(n-1)+(n-2)+...+(n-k)=(n+...+n)-(1+2+...+k)=nk-\frac{k(k+1)}{2}=\frac{2nk-k^2-k}{2}=O(n^2)$

## 9

- $O(n^2)$
- $O(n^3)$
- $O(n^2)$

## 10

### 10.a

$n^2$

### 10.b

$n^2$

### 10.c

$n(1+2+3+...+log_2n)=\frac{n*log_2n(log_2n+1)}{2}=O(nlogn)$

### 10.d

$1+2^1+2^2+...+2^{log_2n}=1+2\frac{2^{log_2n-1}}{2-1}=2n-1=O(n)$

## 11

$\frac{1+2+..+(n-2)}{4(n-2)}+\frac{n-1}{4}+\frac{n}{2}=\frac{7n-3}{8}$

## 12

**不会*

## 13

**不太明白*

但其实就是把

$a{\land}b$改写成这种$(a{\lor}b{\lor}c)\land(a{\lor}b{\lor\lnot}c)$类型

或

$$
a=
(a{\lor}b{\lor}c)
{\land}
(a{\lor\lnot}b{\lor}c)
{\land}
(a{\lor}b{\lor\lnot}c)
{\land}
(a{\lor\lnot}b{\lor\lnot}c)
$$
