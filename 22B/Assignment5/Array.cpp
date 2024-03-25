#include "Array.h"
#include <iostream>
bool Array::isRand = false;
int Array::count = 0;

//Default constructor
Array::Array()
{
    m_size = 0;
    m_ptr = new int[m_size];
}

//Overloaded constructor
Array::Array(int size)
{
    if(!isRand)
    {
        srand(time(0));
        isRand = true;
    }
    m_size = size;
    m_ptr = new int[m_size];
    for(int i = 0; i < m_size; i++)
    {
        count++;
    }
}

//Copy constructor
Array::Array(const Array& rhs)
{
    this->m_size = rhs.m_size;
    this->m_ptr = new int[m_size];
    for(int i = 0; i < m_size; i++)
    {
        this->m_ptr[i] = rhs.m_ptr[i];
    }
    for(int i = 0; i < m_size; i++)
    {
        count++;
    }
}

//Destructor
Array::~Array()
{
    for(int i = 0; i < m_size; i++)
    {
        count--;
    }
    delete[] m_ptr;

}

//returns the size of the array
int Array::getSize() const
{
    return m_size;
}

/*  Accepts an int
    returns the value in the index pointed by pointer
*/
int& Array::operator[](int number)
{
    return m_ptr[number];
}

/*  Accepts ostream and const object passed by ref
    Prints all the elements int the array
    Returns the ostream
*/
ostream& operator<<(ostream& out, const Array& array)
{
    for(int i = 0; i < array.m_size; i++)
    {
        out << array.m_ptr[i] << " ";
    }
    out << endl;
    return out;
}


/*  Accepts a const obj passed by ref
    if lhs obj != rhs, basically the rhs to lhs object
    Returns obj by ref
*/
Array& Array::operator =(const Array& rhs)
{
    if(this != &rhs)
    {
        delete m_ptr;
        for(int i = 0; i < m_size; i++)
        {
            count--;
        }
        m_size = rhs.m_size;
        m_ptr = new int[m_size];
        for(int i = 0; i < m_size; i++)
        {
            this->m_ptr[i] =  rhs.m_ptr[i];
        }
        for(int i = 0; i < m_size; i++)
        {
            count++;
        }
        
    }
    return *this;
}

/*  Accepts a const obj passed by ref
    Overloaded comparison operator
    Returns T/F d/p on conditions
*/
bool Array::operator ==(const Array& rhs)
{
    int smallarr, bigarr = {}; 
    Array small, big = {};
    if(m_size == rhs.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            if(m_ptr[i] == rhs.m_ptr[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        if(m_size < rhs.m_size)
        {
            smallarr = m_size;
            small = *this;
            bigarr = rhs.m_size;
            big = rhs;
        }
        else
        {
            smallarr = rhs.m_size;
            small = rhs;
            bigarr = m_size;
            big = *this;
        }
        for(int i = 0; i < bigarr; i++)
        {
            if(big[i] == small[0])
            {
                for(int i = 0; i < smallarr; i++)
                {
                    if(small[i] == big[i])
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
}



/*  Accepts a const obj passed by ref
    Compare objects
    Returns T/F d/p on conditions
*/
bool Array::operator <(const Array& rhs)
{
    if(m_size == rhs.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            if(m_ptr[i] == rhs.m_ptr[i])
            {
                return true;
            }
            if(m_ptr[i] > rhs.m_ptr[i])
            {
                return false;
            }
        }
    }
    else if(m_size < rhs.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            if(m_ptr[i] == rhs.m_ptr[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

}


/*  Accepts a const obj passed by ref
    Concantenate lhs object to rhs
    Returns obj by ref
*/

Array& Array::operator +=(const Array& rhs)
{
    int tempsize = m_size + rhs.m_size;
    int* tempptr = new int[tempsize];
    //fill temp array with calling obj
    for(int i = 0; i < m_size;i ++)
    {
        tempptr[i] = m_ptr[i];
    }
    for(int i = 0; i < rhs.m_size; i++)
    {
        tempptr[m_size+i] = rhs.m_ptr[i];
    }
    for(int i = 0; i < m_size; i++)
    {
        count--;
    }
    delete[] m_ptr;
    for(int i = 0; i < tempsize; i++)
    {
        count++;
    }
    m_size = tempsize;
    m_ptr = new int[m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_ptr[i] = tempptr[i];
    }
    
    delete[] tempptr;
    return *this;
}

/*  Finds smallest value in the object
    returns the smallest value in object
*/
int Array::operator *()
{
    int smallest = m_ptr[0];
    for(int i = 1; i < m_size; i++)
    {
        if(m_ptr[i] < smallest)
        {
            smallest = m_ptr[i];
        }
    }
    return smallest;
}


/*  Randomly shuffles the elements in the array Object
    Returns obj by ref
*/
Array& Array::operator!()
{
    for(int i = 0; i < m_size; i++)
    {
        int indexswap = rand() % m_size;
        int temp = m_ptr[i];
        m_ptr[i] = m_ptr[indexswap];
        m_ptr[indexswap] = temp;
    }
    return *this;
}


/*  Overloaded postfix increment operator
    Stores calling obj in temp, since we need to return obj before incrementing
    Increment the elements in obj, then returns the temp which will be
    destroyed after it exits the method
*/
Array Array::operator++(int)
{
    Array temp = *this;             //copy constructor will be caleld
    for(int i = 0; i < m_size; i++)
    {
        m_ptr[i] += 1;
    }
    return temp;                    //destroyed after exiting main
}


/*  Overloaded prefix decrement operator
    Decrement the elements in the object by 1
    Returns obj by ref
*/
Array& Array::operator--()
{
    for(int i = 0; i < m_size; i++)
    {
        m_ptr[i] -=1;
    }
    return *this;
}

/*  Keeps track of static var count which counts the number of
    elements in all the objects
*/
int Array::getNumberOfElements()
{
    return count;
}