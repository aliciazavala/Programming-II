#include "Menu.h"
#ifndef Executive_h
#define Executive_h

class Executive{
private:
    int totalNum;
    Player* allPlayers;

public:
    Executive(string fileName);
    void run();
    ~Executive();

};

#endif