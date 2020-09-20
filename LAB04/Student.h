#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student{

  private:

    int m_id;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_level;
    double m_gpa;

  public:

    Student(int id, std::string firstName,std::string lastName,std::string level,double credit,double gpe);
    int getID();
    double getGpa();
    void printStudent();
    ~Student();
    
};
#endif
