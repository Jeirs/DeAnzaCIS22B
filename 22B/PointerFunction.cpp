#include<iostream>
using namespace std;

int NegativeCount(int* first, int* second);

int main()
{
    const int size = 5;
    int arr[size] = { 1, -2, 3, -4, 5};
    int *firstelement = arr;
    int *lastelement  = &arr[size-1];
    cout << "Number of negative numbers is " << NegativeCount(firstelement,lastelement);
}
int NegativeCount(int* first, int* second)
{
    int count = 0;
    for(; first <= second ; first ++)
    {
        if(*first < 0)
        {
            count++;
        }
    }
    return count;
}