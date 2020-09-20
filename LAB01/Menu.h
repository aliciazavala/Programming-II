#include "Player.h"
#ifndef Menu_h
#define Menu_h
#include<string>

class Menu{

private:
   int m_totalNum;
   Player* allPlayers;

public:
    Menu (int totalNum, Player* pointer);
    void optionOne();
    void optionTwo(string team);
    void optionThree(int range1,int range2);   
    void optionFour(int tier);
    void optionFive(string name,string last);

};

#endif

