#include "Employee.h"
#include "Manager.h"
#include <string>
#include <iostream>
using namespace std;

string Employee::getName()const{
	return m_name;
}

string Employee::getLast()const{
	return m_last;
}

int Employee::getID()const{
	return m_id;
}

int Employee::getAge()const{
	return m_age;
}
Employee::Employee(int ID,int age,string name,string last){
	m_id = ID;
	m_name = name;
	m_last = last;
	m_age = age;
}

void Employee::print(){
	cout<< Employee::getID()<<"\nName: "<< Employee::getName()<<" "<<Employee::getLast()<<"\nAge: "<<Employee::getAge()<<'\n';
}
