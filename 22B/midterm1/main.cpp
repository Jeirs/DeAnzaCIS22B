#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct GuestList
{
    int num;
    string* ptr;
};


int main()
{
    GuestList book;
    string filename;
    ofstream outfile;
    cout << "how many guests: ";
    cin  >> book.num;
    cin.ignore();
    book.ptr = new string[book.num];
    for(int i = 0; i < book.num; i++)
    {

        cout << "Enter name of guest#" << (i+1) << ": ";

        getline(cin, book.ptr[i]);
    }
    
    cout << "Enter output filenmame: "; 
    getline(cin, filename);
    outfile.open(filename);
    for(int i = 0; i < book.num; i++)
    {
        outfile << book.ptr[i] << endl;
    }
    
    cout << "The names have been saved to the file" << endl;

    outfile.close();

    delete[] book.ptr;
}