#include <iostream>

using namespace std;

void insertion_sort(int arr[], int size);

int main()
{
    srand(time(nullptr));
    int size = {10};
    int arr[size] = {0};
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertion_sort(arr, size);
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

}

void insertion_sort(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 & arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}