#pragma once
#include <iostream>
using namespace std;
class Array
{
private:
    int m_size;
    int* m_ptr;
    static bool isRand;
    static int count;
public:
    Array();
    Array(int size);
    Array(const Array& rhs);
    ~Array();
    int getSize() const;
    int& operator[](const int number);
    friend ostream& operator<<(ostream& out, const Array& array);
    Array& operator =(const Array& rhs);
    bool operator ==(const Array& rhs);
    bool operator <(const Array& rhs);
    Array& operator +=(const Array& rhs);
    int operator *(); 
    Array& operator!();
    Array operator++(int); //postfix overload since int parameter
    Array& operator--(); //prefix overload since no int parameter
    static int getNumberOfElements();
};

