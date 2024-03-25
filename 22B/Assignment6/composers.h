#pragma once
#include<iostream>
#include <string>

using namespace std;

class Composer
{
private:
    string m_name;      //name
    string m_year;      //date of death
public:
    Composer(string name = "", string death = "");
    bool operator<(const Composer& rhs) const;
    bool operator>(const Composer& rhs) const;
    friend ostream& operator<<(ostream& out, const Composer& rhs);
    bool operator==(const Composer& rhs) const;
    bool operator!=(const Composer& rhs) const;
}; 