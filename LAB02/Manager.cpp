#include "Manager.h"
#include <iostream>
#include <string>
using namespace std;
Manager::Manager(int id,int age, string name, string last,string dept) : Employee(id,age,name,last){
	m_dept = dept;
	m_id = id;
	m_name = name;
	m_last = last;
	m_age = age;
}
string Manager::getDept()const{
	return m_dept;
}
string Manager::getName()const{
	return m_name;
}

string Manager::getLast()const{
	return m_last;
}

int Manager::getID()const{
	return m_id;
}

int Manager::getAge()const{
	return m_age;
}

void Manager::print(){
	cout<< Employee::getID() <<"\nName: "<< Employee::getName()<<" "<<Employee::getLast()<<"\nAge: "<<Employee::getAge()<<"\nManager Dept: "<<Manager::getDept()<<'\n';
}
