#include "BlobFinder.h" 

#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout<<"Incorrect number of inputs!\n";
    }
    else
    {
        try{
        BlobFinder field(argv[1]);
        field.solver();
        field.print();
        }
        catch(runtime_error& errors)
        {
            cout<<errors.what();
        }
    }
    
}