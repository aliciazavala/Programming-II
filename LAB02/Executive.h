#include "Map.h"
#include "Manager.h"
#ifndef Executive_h
#define Executive_h
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Executive{

private:
    int totalEmp;
    int totalDef;
    Employee* allEmp;
    ifstream File1, File2;

    

public:
    Executive(string fileName1, string fileName2);
    void run();
    ~Executive();

};
#endif