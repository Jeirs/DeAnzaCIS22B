#include <iostream>

using namespace std;


int* findSmallest(int* array, int* last);

int main()
{
    int size = 5;
    int ary[5] = {21, 35, 17, 89, 56};
    int *pLast = ary + size -1;
    int *pSmall;
    pSmall = findSmallest(ary, pLast);
    cout << *pSmall << endl;
    return 0;

}

int* findSmallest(int* array, int* last) {
    int* smallestVal;
    while (array < last) {
        if (*array > *last) {
            smallestVal = last;
        }
        last--;
    }
    return smallestVal;
}
