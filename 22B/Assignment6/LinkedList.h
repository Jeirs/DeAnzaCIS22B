#pragma once
#include <iostream>
using namespace std;


//Linkedlist is templated to store all sorts of data
template<class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList();
    ~LinkedList();
    void printList() const;
    void append(const T data);
    void prepend(const T data);
    bool removeFront();
    void insert(const T data);
    bool remove(const T data);
    bool find(const T data);
    bool isEmpty() const;
    T getfirst() const;
    T getlast() const;
};

template<class T>
//LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

//Prints data stored in the linkedlist
template<class T>
void LinkedList<T>::printList() const
{
    Node<T>* ptr = head;
    while(ptr != nullptr)
    {
        cout << ptr->value << " ";
        cout << endl;
        ptr = ptr->next;
    }
}

//Accepts data of any type defined by user
//Insert data to end of list
template<class T>
void LinkedList<T>::append(const T data)    //append adds to end of list
{
    Node<T>* temp = new Node<T>;  
    temp->value = data;
    temp->next = nullptr;   
    if(!head)               //if list empty, new node is the first node
    {                       //temp will be the first node
        head = temp;        //head points to the only node
        tail = temp;        //tail points to the only node
    }
    else                    
    {
        //to keep track of first node in the list
        Node<T>* ptr = head;
        //finds last node
        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        //newnode will be last node, so points to nullptr
        ptr->next = temp;
        tail = temp;
    }
}


////Accepts data of any type defined by user
//Insert data to front of list
template<class T>
void LinkedList<T>::prepend(const T data)   //prepend adds to beginning of list
{
    Node<T>* temp = new Node<T>;
    temp->value = data;
    if(!head)               //if list empty, new node is the first node
    {
        head = temp;        //only one node exists, that node is both head
        tail = temp;        //and tail
        temp->next = nullptr;
    }
    else                    //if list not empty, add to beginning
    {
        temp->next = head;  //create link between new node and head
        head = temp;        //new node is the head now
    }
}


//Destructor
template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* ptr = head;
    while(ptr != nullptr)
    {
        head = head->next;
        delete ptr;
        ptr = head;
    }
}

//Removes the first node in the linkedlist
template<class T>
bool LinkedList<T>::removeFront()
{
    Node<T>* temp = head;
    if(head == nullptr)     //if list is empty,no need to remove
        return false;

    if(head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
    }
    delete temp;
    return true;
}

template<class T>
void LinkedList<T>::insert(const T data)
{
    Node<T>* newnode = new Node<T>;     //Node to be inserted
    newnode->value = data;
    newnode->next = nullptr;
    if(!head)       //if list is empty
    {
        head = newnode;
        tail = newnode;

    }
    else
    {
        Node<T>* firstptr = head;  
        Node<T>* lastptr = tail;
        Node<T>* bignode;//first node is largest node
        if(data < firstptr->value)   //if data is smaller than head
        {
            newnode->next = firstptr;
            head = newnode;
        }
        else if(data > lastptr->value)   //if data is larger than tail
        {
            lastptr->next = newnode;
            tail = newnode;
        }
        else
        {
            //check if next node's data is less than data
            //only change the iteration ptr if that's true
            //so that it points to the correct node for the data to be inserted
            while (firstptr->next && firstptr->next->value < data)
            {
                firstptr = firstptr->next;
            }
            
            bignode = firstptr;
            newnode->next = bignode->next;  //create link before breaking
            bignode->next = newnode;        //create link
        }
    }
}

//Accepts data of any type defined by user
//Removes data that is equal to the argument
template<class T>
bool LinkedList<T>::remove(const T data)
{
    Node<T>* ptr = head;
    Node<T>* prevnode;
    if(!head)                       //if list is empty, returns false
    {
        return false;
    }
    if(ptr->value == data)          //if data is in first node
    {
        ptr = head->next;
        delete head;
        head = ptr;
        return true;
    }
    else
    {
        while(ptr && ptr->value != data) //find if any node matches data
        {
            prevnode = ptr;
            ptr = ptr->next;
        }
        if(!ptr)
        {
            return false;           //not found in list
        }
        if(ptr->next == nullptr)    //node is tail
        {
            prevnode->next = nullptr;
            tail = prevnode;
            delete ptr;
            return true;
        }
        else                        //node is in middle
        {
            prevnode->next = ptr->next;
            delete ptr;
            return true;
        }
    }
}

//Accepts data of any type defined by user
//Searches for the data paramter in the linkedlist
template<class T>
bool LinkedList<T>::find(const T data)
{
    Node<T>* ptr = head;
    Node<T>* prevnode;
    while(ptr)
    {
        if(ptr->value == data)
        {
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}

//Returns true if the list is empty and false if not
template<class T>
bool LinkedList<T>::isEmpty() const
{
    if(!head)
    {
        return true;
    }
    return false;
}

//Returns the first value stored in the linkedlist
template<class T>
T LinkedList<T>::getfirst() const
{
    return head->value;
}

//Returns the last value stored in the linkedlist
template<class T>
T LinkedList<T>::getlast() const
{
    return tail->value;
}
