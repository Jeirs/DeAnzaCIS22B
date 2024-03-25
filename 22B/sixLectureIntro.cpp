#include <iostream>
using namespace std;
int main() {
//	
//
	// int intarr[3] = { 1,2,3 };
	// cout << intarr << endl;              						//Prints address
//	
	// char arr2[] = { 'a', 'b', 'c', '\0' };
	// cout << arr2 << endl;										//Prints abc
//	
	  char arr3[] = "how are you";
	// cout << arr3 << endl;											//Prints how are you, when string is declared as char array , null terminated array
//   you can assign a c string to a pointer

	 char* ptr = arr3;
	// cout << ptr << endl; 											//cout with char ptr prints all
	// cout << *ptr << endl;									   		//dereference char array gives first char
//
	// char* ptr_4 = arr3 + 4;
	// cout << ptr_4 << endl; 
	// cout << *ptr_4 << endl; 
//
//
	//// what if we assign an array of character, but not a c string, to a pointer
	//// and print it?

	char arr1[3] = { 'a', 'b', 'c' };
	cout << arr1 << endl;

	ptr = arr1;
	cout << ptr << endl; 
//	
//	
}

/* #include <iostream>
#include <cstring>
#include <string>

using namespace std;

void function(char* arr);

struct Person {
	string name;
	double weight;
	string birthday;
};

int main()
{
	//char str1[] = "Gravity";
	//function(str1);
	Person data;

	cout << "Please enter name, weight, and birthday. (Aidan Yamada, 741, 4/27/2004)" << endl;
	
	getline(cin, data.name, ',');

	string weight;
	getline(cin, weight, ',');

	getline(cin, data.birthday);

	data.weight = stod(weight);
	cout << "Your name is " << data.name << endl;
	cout << "Your weight is " << data.weight << endl;
	cout << "Your birthday is " << data.birthday << endl;
}

void function(char* arr) {

	char* last = (arr + strlen(arr) - 1);
	
	while (last >= arr) 
	{
		cout << *last;
		last--;
	}
}
 */

//#include <iostream>
//#include <cstring>
//#include <fstream>
//#include <string>
//using namespace std;
//int main()
//{
//	char str[] = "tomorrow ";
//	char s1[20] = "is today";
//	char s2[20] = "another day";
//	char s3[50];
//	char* ptr;
//	cout << sizeof(char) << endl; 
//	cout << sizeof(int) << endl; 
//	cout << sizeof(char*) << endl; 
//	cout << sizeof(int*) << endl; 
//	cout << sizeof(str) << endl; 
//	cout << strlen(str) << endl; 
//	cout << sizeof(s1) << endl; 
//	cout << strlen(s1) << endl; 
//	ptr = s1 + 3; // ptr points to 't' in s1
//	cout << *ptr << endl; // 
//	cout << ptr << endl; // 
//	cout << sizeof(*ptr) << endl; 
//	cout << sizeof(ptr) << endl; 
//	cout << strlen(ptr) << endl; 
//	strcpy_s(s3, str);
//	cout << s3 << endl;
//	strncat_s(s3, s1, 3);
//	cout << s3 << endl;
//    strcat_s(s3, s2);
//	cout << s3 << endl; // 
//	return 0;
//}

