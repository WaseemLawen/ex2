#include <iostream>
#include <string>

#ifndef EX2_PLAYER
#define EX2_PLAYER
#include "Player.h"
#include "utilities.h"

using namespace std;



Player::Player(string name,int maxHP,int force) :
    m_name(name),
    m_maxHP(maxHP),
    m_force(force),
    m_level(1),
    m_HP(maxHP),
    m_coins(0)

{
    if(maxHP<0)
    {
        m_maxHP = MAX_HP;
    }
    if(force<0)
    {
        m_force = DEFAULT_FORCE;
    }

}


void Player::printInfo(){
    printPlayerInfo(m_name.c_str(),m_level,m_force,m_HP,m_coins);
}
void Player::levelUp(){
    if(m_level==10){
        return;
    }
    else{
        m_level++;
    }
}

int Player::getLevel(){
    return m_level;
}

void Player::buff(int strengthen){
    m_force+=strengthen;
}

void Player::heal(int healing){
    if(m_HP+healing>=m_maxHP){
        m_HP=m_maxHP;
    }
    else{
        m_HP+=healing;
    }
}

void Player::damage(int damage_points){
    if(m_HP-damage_points<=0){
        m_HP=0;
    }
    else{
        m_HP-=damage_points;
    }
}

bool Player::isKnockedOut(){
    return !m_HP;
}

void Player::addCoins(int profit){
    m_coins+=profit;
}

bool Player::pay(int payment){
    if(m_coins>=payment){
        m_coins-=payment;
        return true;
    }
    else{
        return false;
    }
}
int Player::getAttackStrength(){
    return (m_level+m_force);
}

#endif