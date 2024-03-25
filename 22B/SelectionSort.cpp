#include <iostream>

using namespace std;

void selection_srt(int arr[], int size);

int main()
{
    int arr[] = {123,100, 87, 235, 1, 910320};

    int length = 6;

    selection_srt(arr, length);
    for(int i = 0; i < length; i++)
    {
        cout << "a[" << i << "]" << arr[i] << endl;
    }
}

void selection_srt(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int minpos = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[minpos])
            {
                minpos = j;
            }
        }
        if(minpos != i)
        {
            int temp = arr[i];
            arr[i]   = arr[minpos];
            arr[minpos]   = temp;
        }
    }
}