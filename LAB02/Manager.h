#include "Employee.h"
#ifndef Manager_h
#define Manager_h
#include <string>
#include <iostream>
using namespace std;

class Manager: public Employee{
	private:
		string m_dept;
		int m_id;
		string m_name;
		string m_last;
		int m_age;

	public:
		string getDept()const;
		int getID()const;
		string getName()const;
		string getLast()const;
		int getAge()const;
		Manager(int id,int age, string name, string last,string dept);
		void print();

}; 

#endif
