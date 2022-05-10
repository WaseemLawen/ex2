#include <iostream>
#include "Player.h"
#include "utilities.h"
using namespace std;



Player::Player(char* name,int maxHP,int force){
    this->name = name;
    this->maxHP=maxHP;
    this->force=force;
}
Player::~Player(){
    delete[] name;
}

void printPlayerInfo(const char* name, int level, int force, int hp, int coins){
    cout<< "Player Details: " << endl;
    cout<< "Name: "<<name<<endl;
    cout<<"Level: "<< level<<endl;
    cout<<"Force: "<< force << endl;
    cout<< "HP: "<< hp<<endl;
    cout << "Coins: "<< coins<<endl;
}
void Player::printInfo(){
    printPlayerInfo(name,level,force,HP,coins);
}
void Player::levelUp(){
    if(level==10){
        return;
    }
    else{
        level++;
    }
}

int Player::getLevel(){
    return level;
}

void Player::buff(int strengthen){
    force+=strengthen;
}

void Player::heal(int healing){
    if(HP+healing>=maxHP){
        HP=maxHP;
    }
    else{
        HP+=healing;
    }
}

void Player::damage(int damage_points){
    if(HP-damage_points<=0){
        HP=0;
    }
    else{
        HP-=damage_points;
    }
}

bool Player::isKnockedOut(){
    return !HP;
}

void Player::addCoins(int profit){
    coins+=profit;
}

bool Player::pay(int payment){
    if(coins>=payment){
        coins-=payment;
        return true;
    }
    else{
        return false;
    }
}
int Player::getAttackStrength(){
    return (level+force);
}