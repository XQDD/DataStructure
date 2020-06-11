#include <iostream>
#include <valarray>
#include "../utils/main.cpp"

using namespace std;

//P26 起泡排序法
void bubblesort1A(valarray<int> &a) {
    bool sored = false;
    auto size = a.size();
    while (!sored) {
        sored = true;
        for (int j = 0; j < size - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sored = false;
            }
        }
        //此时最后的那位已经是最大的了
        --size;
    }

}


int main() {
    valarray a = {1, 2, 3, 4, 5, 6, 7, 8};
    bubblesort1A(a);
    cout << a << endl;
}