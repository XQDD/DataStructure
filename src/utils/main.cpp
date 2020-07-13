#pragma once

#include <iostream>
#include <iterator>
#include <valarray>
#include <sstream>
#include <ctime>

using namespace std;

template<typename T>
void print(valarray<T> arr, char *delimit = " ") {
    copy(begin(arr), end(arr), ostream_iterator<T>(cout, delimit));
}

template<typename T>
void println(valarray<T> arr) {
    print(arr, "\n");
}

template<typename T>
ostream &operator<<(ostream &out, valarray<T> arr) {
    print(arr);
    return out;
}


template<typename T>
string toString(T val) {
    string s;
    stringstream ss;
    ss << val;
    ss >> s;
    return s;
}

class Printable {
public:
    virtual void print() const = 0;

    friend ostream &operator<<(ostream &out, const Printable &p) {
        p.print();
        return out;
    }
};

void init() {
    //设置随机数种子，不然伪随机每次随机出来的数都是一样的
    srand(time(nullptr));

}