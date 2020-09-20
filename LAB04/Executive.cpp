#include "Executive.h"
#include "Student.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
//public

Executive::Executive(std::string file1, std::string file2)
{
	students.open(file1);
	commands.open(file2);
	run(students, commands);
	
}

void Executive::run(std::istream& students, std::istream& commands)
{
    LinkedList<Student> list;
	read(students, list); // on return, "list" will have the student list
	std::string command;
	while (commands >> command)
	{
		if (command == "Class"){
			handleClass(commands, list);
		}
		else if (command == "DropOut"){
			handleDrop(commands, list);
		}
		else if (command == "Honors"){
			handleHonors(commands, list);
		}
		else if (command == "NewStudent"){
			handleNew(commands, list);
		}
		else if (command == "PrintAll"){
			handlePrintAll(commands, list);
		}
		else if (command == "PrintStudent"){
			handlePrint(commands, list);
		}
	}
	list.clear();
	return;
	
}

//private
void Executive::read(std::istream& students, LinkedList<Student>& list)
{	
	int id;
	int i=1;
	double credit, gpe;
	std::string firstName,lastName,level;
	while (students)
	{	
		students>>id >> firstName >> lastName >> level >> credit >> gpe;
		Student stu(id,firstName,lastName,level,credit,gpe);
		list.setEntry(i, stu);
		i++;
	}
	list.remove(1);
}

void Executive::handleClass(std::istream& inp, LinkedList<Student> list)
{	
	int id=1;
	bool found;
	std::string Class;
	inp >> Class;
	std::cout<<Class<<" roster: \n";
	std::cout<<"First Name\tLast Name\tLevel\t\tID\t\tGPA\n";
	for(;;)
	{
		found = false;
		inp>>id;
		if(id == 0){
			break;
		}
		for(int i=1;i<=list.getLength();i++)
		{	
			if(list.getEntry(i).getID() == id )
			{	try{
				list.getEntry(i).printStudent();
				found = true;
				}
				catch(PrecondViolatedExcep& excep){
					std::cout<<excep.what();
				}
			}
		}
		if(found == false)
		{
			std::cout<<"Student with ID: "<<id<<" not found.\n";
		}
	}
	std::cout<<"\n---------------\n\n";	
}

void Executive::handleDrop(std::istream& inp, LinkedList<Student>& list)
{
	int id;
	bool found = false;
	inp>>id;
	for(int i=1;i<=list.getLength();i++)
	{
		if(list.getEntry(i).getID() == id )
		{
				list.remove(i);
				found = true;
  		}  
	}
	if(found == false)
	{	
		std::cout<<"Student with ID: "<<id<<" not found to Drop Out.\n";
		std::cout<<"\n---------------\n\n";	
	}
}

void Executive::handleHonors(std::istream& inp, LinkedList<Student> list)
{
	int min = 0;
	inp>>min;
	std::cout<<"Honors student(s):\n";
	std::cout<<"First Name\tLast Name\tLevel\t\tID\t\tGPA\n";
	for(int i=1; i<=list.getLength(); i++){
		if(list.getEntry(i).getGpa() >= min )
		{
			list.getEntry(i).printStudent();
		}
	}
	std::cout<<"\n---------------\n\n";
}

void Executive::handleNew(std::istream& inp, LinkedList<Student>& list)
{
	int id, credit = 0, gpe = 0;
	std::string firstName,lastName,level;
	inp>> id >> firstName >> lastName >>level;
	Student stu(id,firstName,lastName, level, credit, gpe);
	list.setEntry(1, stu);

}

void Executive::handlePrintAll(std::istream& inp, LinkedList<Student> list)
{
	std::cout<<"All Students: \n";
	std::cout<<"First Name\tLast Name\tLevel\t\tID\t\tGPA\n";
	for(int i=1; i<=list.getLength(); i++){
			list.getEntry(i).printStudent();
	}
	std::cout<<"\n---------------\n\n";
}

void Executive::handlePrint(std::istream& inp, LinkedList<Student> list)
{	
	int id;
	inp>>id;
	bool found = false;
	for(int i=1; i<=list.getLength(); i++)
	{
		if(list.getEntry(i).getID() == id )
		{
			std::cout<<"Student with ID " << id<<" :\n";
			std::cout<<"First Name\tLast Name\tLevel\t\tID\t\tGPA\n";
			list.getEntry(i).printStudent();
			found = true;
			break;
		}	
	}
	if(found == false){
		std::cout<<"Student with that ID "<<id<<" not found.\n";
	}
std::cout<<"\n---------------\n\n";	
}

//destructor
Executive::~Executive()
{

}