#include <iostream>
#include <cstring>

using namespace std;

int lettercount(const char*);

int main()
{
    const char* ptr = "How are you doing?";
    int result = lettercount(ptr);
    cout << result;
}

int lettercount(const char* ptr)
{
    int count = 0;
    for(int i = 0; i < strlen(ptr); i++)
    {
        if(isalpha(ptr[i]))
        {
            count++;
        }
    }
    return count;
}