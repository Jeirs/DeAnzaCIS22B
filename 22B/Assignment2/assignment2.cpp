/*  Date   : 27 Jan 2024
    Program: Prompts user to enter names, number of tests taken and their grades
    respectively which will be stored on the heap and can be accessed by using
    pointers. 
    The displayData function will display the student name and their
    grades for the tests which will be accessed from the heap.
    The cleanHeap function will delete the dynamically allocated memory on the
    heap.
*/


#include <iostream>
using namespace std;

int inputData(string*&, double **&);
void displayData(string*, double**, int);
void cleanHeap(string*, double**, int);
void validate(int);

int main()
{
    string *strPtr;
    double **dbPtr;
    int num_students = inputData(strPtr, dbPtr);
    displayData(strPtr, dbPtr, num_students);
    cleanHeap(strPtr, dbPtr, num_students);
    strPtr = nullptr;
    dbPtr  = nullptr;
}

/*  Receives a pointer to string and
    Receives a pointer to another pointer which is pointing to a double.

    Returns the number of students

    Prompts user to enter number of students then asks for student's names 
    which will be stored in an array on the heap.
    Proceeds to ask the number of tests taken by the student which will be
    stored in index 0 of array size(num_tests + 1)
    The grades will be then stored in the remaining index.
*/
int inputData(string*& names, double**& scores)
{
    int num_students;
    do
    {
        cout << "Enter the number of students: ";
        cin  >> num_students;
        validate(num_students);
    }
    while(num_students <= 0);

    names = new string[num_students];
    scores = new double*[num_students];

    for(int i = 0; i < num_students; i++)
    {
        cout << "Enter the name of student: ";
        cin.ignore();
        getline(cin, names[i]);
        int num_tests;
        do
        {
            cout << "Enter the number of tests " << names[i] << " took: ";
            cin  >> num_tests;
            validate(num_tests);
        }
        while(num_tests <= 0);

        scores[i] = new double[num_tests+1];

        //save the num: of tests student has taken in index 0
        scores[i][0] = num_tests;        //*(*scores+i)+0) same as scores[i][0]

        for(int j = 1; j <= scores[i][0]; j++)
        {
            do
            {
                cout << "Enter score " << (j) << ": ";
                cin  >> scores[i][j];
                if(scores[i][j] < 0 || scores[i][j] > 100)
                {
                    cout << "Invalid. Please enter a score between "<<
                    "0 and 100, inclusive." << endl;
                }
            } 
            while (scores[i][j] < 0 || scores[i][j] > 100);
        }
    }
    return num_students;
}


/*  Receives a pointer to string and
    Receives a pointer to another pointer which is pointing to a double.

    Returns nothing

    Uses a nested for loop to print the student name first and the amount of
    tests student has taken and lastly printing their grades.
*/
void displayData(string* names, double** scores, int numstudents)
{
    cout << "You have " << numstudents << " students in the system." << endl;
    for(int i = 0; i < numstudents; i++)
    {
        cout << "Name of student #" << (i+1) << ": " << *(names + i) << endl;
        cout << "Scores are: ";
        for(int j = 1; j <= *(*(scores+i)+0); j++)
        {
            cout << *(*(scores+i)+j) << " ";
        }
        cout << endl;
    }
}

/*  Receives a pointer to string and
    Receives a pointer to another pointer which is pointing to a double.

    Returns nothing

    Delete string elements in the array pointer is pointing at
    For loop to delete an array of double type being pointed by
    an array of pointers
    Deleting the array of pointers
*/
void cleanHeap(string* names, double** scores, int numstudents)
{   
    delete[] names;

    for(int i = 0; i < numstudents; i++)
    {
        delete[] scores[i];
    }

    delete[] scores;

}


/*  Receives an integer
    Returns nothing
    Prompts user to enter again if user enters a value <= 0 
*/
void validate(int number)
{
    if(number <= 0)
    {
        cout << "Please enter a positive value." << endl;
    }
}



/* Sample Run
Enter the number of students: 3
Enter the name of student: Chicken
Enter the number of tests Chicken took: 3
Enter score 1: 66.4
Enter score 2: 101
Invalid. Please enter a score between 0 and 100, inclusive.
Enter score 2: 99
Enter score 3: -3
Invalid. Please enter a score between 0 and 100, inclusive.
Enter score 3: 44.3
Enter the name of student: Beer
Enter the number of tests Beer took: 2
Enter score 1: 66.5
Enter score 2: -22
Invalid. Please enter a score between 0 and 100, inclusive.
Enter score 2: 0
Enter the name of student: Mark
Enter the number of tests Mark took: -1
Please enter a positive value.
Enter the number of tests Mark took: 0
Please enter a positive value.
Enter the number of tests Mark took: 1
Enter score 1: 100
You have 3 students in the system.
Name of student #1: Chicken
Scores are: 66.4 99 44.3
Name of student #2: Beer
Scores are: 66.5 0
Name of student #3: Mark
Scores are: 100 
*/