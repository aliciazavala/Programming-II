#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <iostream>

using namespace std;

class Staff
{
    private:
    string fName;
    string lName;
    int priorityN;

    public:
    Staff();
    Staff(string First,string Last, int Number);
    ~Staff();
    string getLast()const;
    string getFirst()const; 
    int getPriority()const;
    bool operator <(const Staff& x ) const;
    bool operator >(const Staff& x ) const;
    void operator =(Staff& x );
    friend ostream& operator<<(ostream &out, const Staff& x)
        {
            out<< x.fName <<" "<<x.lName<<" with priority "<<x.priorityN;
            return out; 
        }
};
#endif