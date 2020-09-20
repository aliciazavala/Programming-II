#include "Function.h"
using namespace std;

Function::Function(string name, string status)
{
    m_name = name;
    m_status = status;
}

string Function::getName()
{
    return(m_name);
}

string Function::getStatus()
{
    return(m_status);
}
bool Function::Status()
{
    if(getStatus() == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}   