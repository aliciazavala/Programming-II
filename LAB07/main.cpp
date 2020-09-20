#include "ElectricField.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout<<"Incorrect number of inputs!\n";
    }
    else
    {
        ElectricField field("sample.txt");
        field.print();
        field.solver();
        field.print();
    }
    
}