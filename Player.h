#define DEFAULT_FORCE 5
#define MAX_HP 100
#include <string>
using std::string;
using std::iostream;

#pragma once
class Player
{
    string m_name;
    int m_maxHP;
    int m_force;
    int m_level;
    int m_HP;
    int m_coins;

    public:
    Player()=default;
    Player(string name,int maxHP=MAX_HP,int force=DEFAULT_FORCE);
    Player(const Player& player)=default;
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int strengthen);
    void heal(int healing);
    void damage(int damage_points);
    bool isKnockedOut();
    void addCoins(int profit);
    bool pay(int payment);
    int getAttackStrength();
    Player& operator=(const Player& other) = default;
    ~Player() = default;
};

