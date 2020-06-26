#pragma once

#include <iostream>
#include <iterator>
#include <valarray>

using namespace std;

template <typename T>
void print(valarray<T> arr, char *delimit = " ")
{
    copy(begin(arr), end(arr), ostream_iterator<T>(cout, delimit));
}

template <typename T>
void println(valarray<T> arr)
{
    print(arr, "\n");
}

template <typename T>
ostream &operator<<(ostream &out, valarray<T> arr)
{
    print(arr);
    return out;
}

class Printable
{
public:
    virtual void printAll() const = 0;
    friend ostream &operator<<(ostream &out, const Printable &p)
    {
        p.printAll();
        return out;
    }
};