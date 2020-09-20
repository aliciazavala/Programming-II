#include "Student.h"
#include <iostream>
#include <string>

Student::Student(int id, std::string firstName,std::string lastName,std::string level,double credit,double gpe){

  m_id = id;
  m_firstName = firstName;
  m_lastName =  lastName;
  m_level = level;
  if(credit != 0 )
  {
  m_gpa = (gpe/credit);
  }
  else{
    m_gpa=0;
  }

}

int Student::getID(){
  return(m_id);
}

double Student::getGpa(){
  return(m_gpa);
}

void Student::printStudent(){

  std::cout<<m_firstName<<"\t\t"<<m_lastName<<"\t\t";
  if(m_level=="Senior" || m_level=="Junior")
  {
  std::cout<<m_level<<"\t\t"<<m_id<<"\t\t"<<m_gpa <<'\n';
  }
  else{
    std::cout<<m_level<<"\t"<<m_id<<"\t\t"<<m_gpa <<'\n';
  }

}

Student::~Student(){
}
