#include <iostream>
#include <string>

using namespace std;

void insertion(string items[], int length);

int main()
{
    string items[] = {"Homework", "Watch", "Bottle", "Aeroplane", "Continent", "Vygotsky", "Zero"};
    int length = 7;
    insertion(items, length);
    int i = 0;
    while(i < length)
    {
        cout << "items[" << i << "] " << items[i] << endl;
        i++;
    }
}

void insertion(string items[], int length)
{
    for(int i = 1; i < length; i++)
    {
        string key = items[i];  //key
        int j = i - 1;          //index of sorted
        while(j >= 0 && items[j] > key)
        {
            items[j+1] = items[j];
            j--;
        }
        items[j+1] = key;
    }
}