#include <iostream>
#include <valarray>
#include <bitset>
#include "../utils/main.cpp"

using namespace std;

//P62 2.7 求最长顺序子数组得长度
int longestIncreasingOrderLength(valarray<int> &a)
{
    auto n = a.size();
    int length;
    int i, i1, i2, k;

    for (i = 0, length = 1; i < n - 1; i++)
    {
        for (i1 = k = i, i2 = i + 1; k < n - 1 && a[k] < a[k + 1]; k++, i2++)
        {
            if (length < i2 - i1 + 1)
            {
                length = i2 - i1 + 1;
            }
        }
    }

    return length;
}

int main()
{
    valarray a = {1, 2, 4, 3, 4, 5, 9, 6, 4};
    cout << longestIncreasingOrderLength(a) << endl;
}