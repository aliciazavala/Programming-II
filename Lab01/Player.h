#ifndef Player_h
#define Player_h
#include <string>
using namespace std;

class Player{
private:
    string m_name;
    string m_lastName;
    string m_team;
    int m_byeWeek;
    int m_expRank;
    int m_tier;

public:
    string getName() const;
    string getLast() const;
    string getTeam() const;
    int getbyeWeek() const;
    int getRank() const;
    int getTier() const;

    void setName(string name);
    void setLast(string lastName);
    void setTeam(string team);
    void setbyeWeek(int byeWeek);
    void setRank(int expRank);
    void setTier(int tier);

};

#endif