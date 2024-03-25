#include "composers.h"
#include <string>

using namespace std;


Composer::Composer(string name, string death)
{
    m_name = name;
    m_year = death;
}

bool Composer::operator<(const Composer& rhs) const
{
    return m_year < rhs.m_year;
}

bool Composer::operator>(const Composer& rhs) const
{
    return m_year > rhs.m_year;
}

ostream& operator<<(ostream& out, const Composer& rhs)
{
        out << rhs.m_name << " -" << rhs.m_year;
        return out;
}

bool Composer::operator==(const Composer& rhs) const
{
    return m_name == rhs.m_name;
}

bool Composer::operator!=(const Composer& rhs) const
{
    return !(operator==(rhs));
}

