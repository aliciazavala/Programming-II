#include "Menu.h"
#include <string>
#include <iostream>
using namespace std;

Menu::Menu(int totalNum, Player* pointer){
    m_totalNum = totalNum;
    allPlayers = pointer;
}

void Menu::optionOne(){
    cout<<"\n";
    for(int i=1;i<m_totalNum;i++){
        cout<<allPlayers[i].getRank()<<": "<< allPlayers[i].getLast()<<", "<< allPlayers[i].getName()<<" "<<allPlayers[i].getTeam()<<" "<<allPlayers[i].getbyeWeek()<<" ("<<allPlayers[i].getTier()<<") \n";
    }
}

void Menu::optionTwo(string team){
     cout<<"\n";
    bool proof = false;
    do{
        for(int i=0;i<m_totalNum;i++){
            if (allPlayers[i].getTeam() == team){
                proof = true;
            }
        }
        if(proof == true){
            cout<<"Players in "<<team<<": \n";
            for(int i=0;i<m_totalNum;i++){
                if (allPlayers[i].getTeam() == team){
                cout<<allPlayers[i].getRank()<<": "<< allPlayers[i].getLast()<<", "<< allPlayers[i].getName()<<" "<<allPlayers[i].getTeam()<<" "<<allPlayers[i].getbyeWeek()<<" ("<<allPlayers[i].getTier()<<") \n";
                }
            }
        }
        if(proof == false){
            cout<<"Invalid input, try again.\nEnter team: ";
            cin>>team;
        }
    } while(proof == false);
}

void Menu::optionThree(int range1,int range2){
     cout<<"\n";
    bool valid = false;
    do{
        if(range1 > 0 && range2 > 0 && range2 < m_totalNum && range1<m_totalNum){
            valid = true;
            if(range1<range2 || range1==range2){
                cout<<"\nPlayers within given rank: \n";
                for(int i=0;i<m_totalNum;i++){
                    if(allPlayers[i].getRank() >= range1 && allPlayers[i].getRank() <= range2){
                        cout<<allPlayers[i].getRank()<<": "<< allPlayers[i].getLast()<<", "<< allPlayers[i].getName()<<" "<<allPlayers[i].getTeam()<<" "<<allPlayers[i].getbyeWeek()<<" ("<<allPlayers[i].getTier()<<") \n";
                    }
                }
            }

        }
        if(valid == false){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input, try again.\nPlease enter range from 1 - "<<(m_totalNum-1)<<" : ";
            cin>>range1;
            cin>>range2;
        }
    }while(valid == false);
}   

void Menu::optionFour(int tier){
     cout<<"\n";
    bool valid = false;
    do{
        if(tier > 0 && tier < 10){
            valid = true;
            cout<<"Players with tier ("<<tier<<"):\n";
            for(int i=1;i<m_totalNum;i++){
                if(allPlayers[i].getTier() == tier){
                    cout<<allPlayers[i].getRank()<<": "<< allPlayers[i].getLast()<<", "<< allPlayers[i].getName()<<" "<<allPlayers[i].getTeam()<<" "<<allPlayers[i].getbyeWeek()<<" ("<<allPlayers[i].getTier()<<") \n";
                }
            }
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input, try again.\nInput tier number: ";
            cin>> tier;
        }
    }while( valid == false);
}

void Menu::optionFive(string name,string last){
    int move,current,t_byeW,t_tier;
    bool found = false;
    string t_name,t_last,t_team;

    do{
        for(int i=0;i<m_totalNum;i++){
            if (allPlayers[i].getName() == name && allPlayers[i].getLast() == last){
                found = true;
                current = i;
            }
        }
    
        if(found == false){
            cout<<"Invalid name or last name, try again: ";
            cin>>name;
            cin>>last;
        }
    }while(found == false);

if(found == true){
    cout<<"Player's current rank: "<<current<<'\n';
    for(;;){
        cout<<"Enter player's new rank: ";
        cin>>move;
        if(move>0 && move<m_totalNum){
            break;
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input, try again.\n";
        }
    }
    t_name = allPlayers[current].getName();
    t_last = allPlayers[current].getLast();
    t_team = allPlayers[current].getTeam();
    t_byeW = allPlayers[current].getbyeWeek();
    t_tier = allPlayers[current].getTier();

    if(move<current){
        for(int j=current;j>move;j--){
        allPlayers[j].setName(allPlayers[j-1].getName());
        allPlayers[j].setLast(allPlayers[j-1].getLast());
        allPlayers[j].setTeam(allPlayers[j-1].getTeam());
        allPlayers[j].setbyeWeek(allPlayers[j-1].getbyeWeek());
        allPlayers[j].setTier(allPlayers[j-1].getTier());
        }
    }    
    else{
        for(int j=current;j<move;j++){
        allPlayers[j].setName(allPlayers[j+1].getName());
        allPlayers[j].setLast(allPlayers[j+1].getLast());
        allPlayers[j].setTeam(allPlayers[j+1].getTeam());
        allPlayers[j].setbyeWeek(allPlayers[j+1].getbyeWeek());
        allPlayers[j].setTier(allPlayers[j+1].getTier());
        }
    }
    allPlayers[move].setName(t_name);
    allPlayers[move].setLast(t_last);
    allPlayers[move].setTeam(t_team);
    allPlayers[move].setbyeWeek(t_byeW);
    allPlayers[move].setTier(t_tier);           
            
}
cout<<"\nAll changes done correctly. \n";
}