#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10;
    char arr[SIZE] = { 'a', 'b', 'c', 'd', 'A', 'w', 'y', 'a', 'z', 'M'};   
    
    for (char* pointer = &arr[SIZE-1] ; pointer >= arr; pointer--)
    {
        cout << *pointer << " ";
    }
}
