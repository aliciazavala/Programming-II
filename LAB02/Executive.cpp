#include "Executive.h"
#include "Map.h"
#include "Employee.h"
#include "Manager.h"
#include <string>
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

Executive::Executive(string fileName1, string fileName2){
    File1.open(fileName1);
    File2.open(fileName2);
    if(File1.is_open()==true || File2.is_open()==true)
    {
        File1>>totalDef;
        File2>>totalEmp;
        run();
    }
    else{
        cout<<"\nInvalid Input.\n";
    }
    
}

void Executive::run(){
    if(File1.is_open()==true || File2.is_open()==true){
        bool quit = false;
        char option;
        string word,definition,type,dept,name,last;
        int ID,age;
        //def
        Map <string, string> definitions(totalDef);
        for(int i=0;i<totalDef;i++){
            File1>>word;
            getline(File1,definition);
            definitions.add(word,definition,i);
        }    
        //emp
        Map <int, Employee*> employee(totalEmp);
        for(int i=0;i<6;i++){
            File2>>ID;
            File2>>type;
            File2>>name;
            File2>>last;
            File2>>age;
            if(type == "Manager"){
                File2>>dept;
                allEmp = new Manager(ID,age,name,last,dept);
                employee.add(ID, allEmp, i);
            }
            else if(type == "Employee"){
                allEmp = new Employee(ID,age,name,last);
                employee.add(ID, allEmp, i);
            } 
        }    

        while(quit == false){
            cout<<"\nD word\nE id\nQ\n";
            cin>>option;
            if(option == 'D'){
                cout<<"Enter word: ";
                cin>>word;
                
                if(definitions.lookup(word,definition) == true){
                
                    cout<<word<<" : "<<definitions.returnr()<<'\n';
                }
                else{
                    cout<<"Word not found.\n";
                }

            } 
            else if(option == 'E'){
                cout<<"Input Employee ID number: ";
                cin>>ID;
                if(employee.lookup(ID,allEmp) == true){
                   employee.returnr()->print();
                }
                else{
                    cout<<"Employee not found.\n";
                }
            }
            else if(option == 'Q'){
                cout<<"\nExiting...\n\n";
                File1.close();
                File2.close();
                quit = true;
            }
            else{
                cout<<"Invalid option, try again.\n";
            }
        }
    } 
}

Executive::~Executive(){
}