#include <iostream>
using namespace std;

/* class Student
{
    private:
        string name;
        float gpa;
    public:
        void setName(string n)
        {
            name = n;
        }
        void setGpa(float g)
        {
            gpa = g;
        }
        string getName() const
        {
            return name;
        }
        float getGpa() const
        {
            return gpa;
        }
};

int main()
{
    Student student1;
    string name;
    float grade;
    cout << "Name of student: ";
    getline(cin, name);
    student1.setName(name);
    cout << "Grade of student: ";
    cin  >> grade;
    student1.setGpa(grade);
    cout << "Student's name is " << student1.getName() << " and GPA is " << student1.getGpa() << endl;
} */

class Int
{
    private:
        int* ptr;
    public:
        Int();
        Int(int);
        int getValue() const;
        ~Int();
};

int main()
{
    Int naruto;
    Int sasuke(3);
    sasuke.getValue();
}

Int::Int()
{
    ptr = new int;
    cout << "Default constructor called" << endl;
}

Int::Int(int value)
{
    ptr = &value;
    cout << "Overloaded constructor called" << endl;
}

int Int::getValue() const
{
    cout << ptr << endl;
    return *ptr;
}

Int::~Int()
{
    delete ptr;
    cout << "deConstructor" << endl;
}