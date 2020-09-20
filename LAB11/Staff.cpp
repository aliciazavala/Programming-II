#include "Staff.h"
Staff::Staff()
{

}

Staff::Staff(string First,string Last, int Number)
{
    fName = First;
    lName = Last;
    priorityN = Number;
}

Staff::~Staff()
{

}

string Staff::getFirst()const
{
    return(fName);
}
string Staff::getLast()const
{
    return(lName);
}
int Staff::getPriority()const
{
    return(priorityN);
}

bool Staff::operator <(const Staff& x ) const
{
    return(this->priorityN < x.getPriority());
}

bool Staff::operator >(const Staff& x ) const
{
    return (this->priorityN > x.getPriority());
}

void Staff::operator=( Staff& x )
{
    fName = x.getFirst();
    lName = x.getLast();
    priorityN = x.getPriority();
}
