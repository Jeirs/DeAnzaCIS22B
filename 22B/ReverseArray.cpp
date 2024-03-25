#include <iostream>
using namespace std;

void ReverseArray(int *first, int *second, int size);

int main()
{
    const int size = 5;
    int array1[size] = {1,2,3,4,5};
    int array2[size];
    ReverseArray(array1, array2, size);
    for(int i = 0; i < size; i++)
    {
        cout << array2[i] << " ";
    }

}

void ReverseArray(int *first, int *second, int size)
{
    second = second + size - 1;
    for(int i = 0; i < size ; i++)
    {
        *second = *first;
        first++;
        second--;
    }
}