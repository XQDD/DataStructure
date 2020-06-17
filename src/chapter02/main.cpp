#include <iostream>
#include <valarray>
#include <bitset>
#include "../utils/main.cpp"

using namespace std;

//P26 1.1 起泡排序法
void bubbleSort1A(valarray<int> &a) {
    bool sorted = false;
    auto size = a.size();
    while (!sorted) {
        sorted = true;
        for (int j = 0; j < size - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sorted = false;
            }
        }
        //此时最后的那位已经是最大的了
        --size;
    }

}


//P34 1.2 正整数二进制展开数中位1总数的统计
int countOnes(unsigned int n) {
    int count = 0;
    while (n) {
        count += (1 & n); //检测最低位是否为1，1则计数
        n >>=   1;
    }
    return count;
}

//P38 1.5 线性递归求和
int sum(int A[], int n) {
    if (n <= 0) {
        return 0; //递归基
    } else {
        //取出最后一位，重复此操作，则变成取出所有数字，然后加起来
        return sum(A, n - 1) + A[n - 1];
    }
}


int main() {
    //起泡排序
    valarray a = {1, 2, 3, 4, 5, 6, 7, 8};
    bubbleSort1A(a);
    cout << a << endl;

    //计算二进制1的个数
    auto v1 = 125125;
    cout << countOnes(v1) << endl;
    bitset<32> x(v1);
    cout << x << endl;

    //线性递归求和
    int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(v2, 10) << endl;
}