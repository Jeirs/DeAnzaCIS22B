#include<iostream>

using namespace std;

int main()
{
    char arr[6] = {'z', 'x', 'm', 's', 'e', 'h'};
    char *ptr = arr+6-1;
    char temp = *ptr;
    while(ptr > arr)
    {
        *ptr = *(ptr - 1);
        ptr--;
    }

    *arr = temp;
    for(int i = 0; i < 6; i++)
    {
        cout << *(arr+i) << " ";
    }
}

//do tomorrow
