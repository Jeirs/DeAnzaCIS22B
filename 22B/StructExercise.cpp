#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    double weight;
    string birthday;
};


/* int main()
{
    Person humans[3];
    for(int i = 0; i < 3; i++)
    {
        cout << "Enter name, weight in pounds, birthday: " << endl;
        getline(cin, humans[i].name, ',');
        string temp;
        getline(cin, temp, ',');
        humans[i].weight = stod(temp);
        getline(cin, humans[i].birthday);
    }

    for(int i = 0; i < 3; i++)
    {
        cout << humans[i].name << " " << humans[i].weight << " pounds, " << "born on " << humans[i].birthday << endl;
    }
} */

int main()
{
    int size;
    string temp;
    cout << "Enter the number of persons: ";
    cin  >> size;
    Person* ptr = new Person[size];
    for(int i = 0; i < size; i++)
    {
        cout << "Enter name, weight in pd, birthdate:";
        getline(cin, ptr[i].name, ',');
        getline(cin, temp, ',');
        ptr[i].weight = stod(temp);
        getline(cin, ptr[i].birthday);
    }
    for(int i = 0; i < size; i++)
    {
        cout << ptr[i].name << ", " << ptr[i].weight << " pounds, " << ptr[i].birthday << endl;
    }
}