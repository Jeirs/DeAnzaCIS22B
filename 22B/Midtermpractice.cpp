#include <iostream>
#include <fstream>
using namespace std;

void doubleElements(int* arrptr, int num);

int main()
{
    ifstream filein;
    string filename;
    int entries;
    cout << "Enter filename: ";
    getline(cin, filename);
    cout << "Enter entries: ";
    cin  >> entries;
    filein.open(filename);
    while(!filein)
    {
        cout << "Enter filename: ";
        getline(cin, filename);
        filein.open(filename);
        cout << "Enter entries: ";
        cin  >> entries;
    }
    int* ptr = new int[entries];   //dynamic array on the heap
    if(filein.is_open())
    {
        cout << "File opened successfully" << endl;
        for(int i = 0; i < entries; i++)
        {
            filein >> ptr[i];
        }
        filein.close();
        cout << "Populated array before being doubled: ";
        for (int i = 0; i < entries; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;

        doubleElements(ptr, entries);

        cout << "Populated array after being doubled: ";
        for (int i = 0; i < entries; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;

    }

    delete[] ptr;
}

//arrptr points to an array of integers
//num = number of elements
void doubleElements(int* arrptr, int num)
{
    for(int i = 0; i < num; i++)
    {
        arrptr[i] *= 2;
    }
}