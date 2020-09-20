#include "Player.h"
#include <string>
using namespace std;

string Player::getName()const{
    return m_name;
}
string Player::getLast()const{
    return m_lastName;
}

string Player::getTeam()const{
    return m_team;
}
int Player::getbyeWeek()const{
    return m_byeWeek;
}

int Player::getRank()const{
    return m_expRank;
}

int Player::getTier()const{
    return m_tier;
}

void Player::setName(string name){
    m_name = name;
}
void Player::setLast(string lastName){
    m_lastName = lastName;
}
void Player::setTeam(string team){
    m_team = team;
}
void Player::setbyeWeek(int byeWeek){
    m_byeWeek = byeWeek;
}
void Player::setRank(int expRank){
    m_expRank = expRank;
}
void Player::setTier(int tier){
    m_tier = tier;
}

