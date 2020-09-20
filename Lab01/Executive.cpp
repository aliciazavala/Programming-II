#include "Executive.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Executive::Executive(string fileName){
    ifstream inFile;
    inFile.open(fileName);
if(inFile.is_open()==true){
    inFile >> totalNum;
    totalNum=totalNum+1;
    if(totalNum>0){

    allPlayers = new Player[totalNum]; 
    for(int i=1;i<totalNum;i++){
    string name;
    inFile>>name;
    allPlayers[i].setName(name);

    string lastName;
    inFile>>lastName;
    allPlayers[i].setLast(lastName);

    string team;
    inFile>>team;
    allPlayers[i].setTeam(team);

    int byeWeek;
    inFile>>byeWeek;
    allPlayers[i].setbyeWeek(byeWeek);

    int expRank;
    inFile>>expRank;
    allPlayers[i].setRank(expRank);

    int tier;
    inFile>>tier;
    allPlayers[i].setTier(tier);
    }
}
    else{
        cout<<"Invalid Input";
    }
}
    inFile.close();
}


void Executive::run(){
    Menu options(totalNum,allPlayers);
    int option,range1,range2,tier;
    string team,name,lastN;
    for(;;){

        cout<<"\n1. Display all RBs by ranking.\n2. Display all RBs from a specific team.\n3. Display all RBs from a ranking range.\n4. Display a tier.\n5. Edit a ranking.\n6. Exit program.\n\n";
        cin>>option;

        if(option>0 && option<7){

            if(option==1){
                options.optionOne();
            }

            if(option==2){
                cout<<"Enter team: ";
                cin>>team;
                options.optionTwo(team);
            }

            if(option==3){
                cout<<"Enter range: ";
                cin>>range1>>range2;
                options.optionThree(range1,range2);
            }

            if(option==4){ 
                cout<<"Enter tier number: ";
                cin>>tier;
                options.optionFour(tier);
            
            }

            if(option==5){
                cout<<"Enter first and last name: ";
                cin>>name>>lastN;
                options.optionFive(name,lastN);
            }

            if(option==6){
                cout<<"\nExiting...\n\n";
                break;
            }

        }

        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "Invalid option, try again\n\n";

        }

    }

}

Executive::~Executive(){
    delete[] allPlayers;

}
