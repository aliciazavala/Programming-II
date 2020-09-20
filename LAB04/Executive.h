#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "LinkedList.h"
#include "Student.h"

#include <fstream>
#include <iostream>
#include <string>

class Executive{
    private:
    ifstream students;
    ifstream commands;
    void read(std::istream& students, LinkedList<Student>&  list);
    void handleClass(std::istream& inp, LinkedList<Student> list);
    void handleDrop(std::istream& inp, LinkedList<Student>& list);
    void handleHonors(std::istream& inp, LinkedList<Student> list);
    void handleNew(std::istream& inp, LinkedList<Student>& list);
    void handlePrintAll(std::istream& inp, LinkedList<Student> list);
    void handlePrint(std::istream& inp, LinkedList<Student> list);

    public:
    Executive(std::string file1, std::string file2);  
    void run(std::istream& inp, std::istream& commands);
    ~Executive();
 

};
#endif


