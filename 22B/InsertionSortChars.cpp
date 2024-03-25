#include <iostream>

using namespace std;

void insertion(char arr[], int length);

int main()
{
    char arr[] = {'y', 'f', 'z', 'a', 'c', 'h','m'};
    int length = 7;
    insertion(arr, length);
    int i = 0;
    while(i < length)
    {
        cout << "arr[" << i << "] " << arr[i] << endl;
        i++;
    }
}

void insertion(char arr[], int length)
{
    for(int i = 1; i < length; i++)
    {
        char key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}