#include <iostream>
using namespace std;

class Numberarray
{
    private:
        double* ptr;
        int size;
    public:
        Numberarray();
        Numberarray(double number, int length);
        void setNum(int index, double value);
        double getNum(int index) const;
        void displayall()const;
        ~Numberarray();
};
int main()
{
    Numberarray arr1;
    Numberarray arr2(10, 4);
    arr2.setNum(2, 150);
    cout << arr2.getNum(2) << endl;
    arr2.displayall();
    cout << endl;
}

Numberarray::Numberarray()
{
    ptr = new double[10];
    size = 10;
    for(int i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }
    cout << "Default constructor" << endl;
}

Numberarray::Numberarray(double number, int length)
{
    size = length;
    ptr = new double[size];
    for(int i = 0; i < length; i++)
    {
        ptr[i] = number;
    }
}

void Numberarray::setNum(int index, double value)
{
    ptr[index] = value;
}

double Numberarray::getNum(int index) const
{
    return ptr[index];
}

void Numberarray::displayall() const
{
    for(int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
}

Numberarray::~Numberarray()
{
    delete[] ptr;
    cout << "Destructor" << endl;
}

