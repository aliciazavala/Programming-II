#ifndef Employee_h
#define Employee_h
#include <string>
#include <iostream>
using namespace std;


class Employee{
	private: 
		int m_id;
		string m_name;
		string m_last;
		int m_age;

	public:
		int getID()const;
		string getName()const;
		string getLast()const;
		int getAge()const;
		Employee(int ID,int age,string name,string last);
		virtual void print();


};
#endif

