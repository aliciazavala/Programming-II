/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#include "Executive.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeContainer.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
using namespace std;

Executive::Executive(string filename){
	inFile.open(filename);
	if(inFile.is_open()==true){//checks valid file
		inFile>>totalShapes;
	}
	else{
	cout<<"Incorrect input.";
	}

void Executive::run(){
	Shape* shapePtr;
	ShapeContainer container(totalShapes);
	bool quit = false;
	string shape, command;
	double radius,width,length,base,height;

	while(quit == false){
		shapePtr = nullptr;
		//Shape* temp[totalShapes];
		createArray(totalShapes);
		inFile>>command;
		int n=0;
		if(command == "ADD"){//checks if file will add shapes
			inFile>>index;
			inFile>>shape;
			if(shape == "TRI"){//add triangle shape
				inFile>>base;
				inFile>>height;
				//Triangle triangle(base,height);
				temp[n] = new Triangle(base,height);
				//shapePtr = &triangle;
				shapePtr = temp[n];
				try{
					container.add(shapePtr, index);//function checks if there is any index error or shapePtr pointing to nullptr and adds shape
					n++;
				}
				catch(runtime_error& except){
       			 	cout<<except.what();//cout exception if invalid input
  				}  
			}
			if(shape == "CIR"){//add cirlce shape
				inFile>>radius;
				//Circle circle(radius);
				//shapePtr = &circle;
				temp[n] = new Circle(radius);
				shapePtr = temp[n];
				try{
					container.add(shapePtr, index);//function checks if there is any index error or shapePtr pointing to nullptr and adds shape
					n++;
				}
				catch(runtime_error& except){
					cout<<except.what();//cout exception if invalid input
  				}  
			}
			if(shape == "REC"){//add rectangle shape
				inFile>>length;
				inFile>>width;
				//Rectangle rectangle(length,width);
				//shapePtr = &rectangle;
				temp [n] = new Rectangle(length,width);
				shapePtr = temp[n];
				try{
					container.add(shapePtr, index);//function checks if there is any index error or shapePtr pointing to nullptr and adds shape
					n++;
				}
				catch(runtime_error& except){
					cout<<except.what();//cout exception if invalid input
  				}  
			}
		}
		else if(command == "DELETE"){
			inFile>>index;
			try{
				container.remove(index);//function checks if there is any index error or shapePtr pointing to nullptr and removes shape
			}
			catch(runtime_error& except){
				cout<<"Error at index "<<index<<" : "<<except.what()<<endl;
			}
			
		}
		else if(command == "PRINT"){
			inFile>>index;
			double area;
			try{
				shape = container.shapeName(index);
				area = container.area(index);
				cout<<"Shape at index "<<index<<" : "<<shape<<" area = "<<area<<'\n';
			}
			catch(runtime_error& except){
				cout<<"Shape at index "<<index<<" : "<<except.what()<<endl;
			}

		}
		else if(command == "EXIT"){
			cout<<"Exiting...\n\n";
			delete shapePtr;
			inFile.close();
			for( int j=0 ;j<n;n++){
			delete temp[j];
			}
			quit = true;
			
		}
	}
} 

Executive::~Executive(){

}
