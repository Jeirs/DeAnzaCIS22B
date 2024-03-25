#include <iostream>

using namespace std;

void insertion(int arr[], int length);

int main()
{
    int arr[] = {90, 25, 12, 1, 14941, 44};
    int length = 6;
    insertion(arr, length);
    int i = 0;
    while(i < length)
    {
        cout << "arr[" << i << "] " << arr[i] << endl;
        i++;
    }

}

void insertion(int arr[], int length)
{
    for(int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}