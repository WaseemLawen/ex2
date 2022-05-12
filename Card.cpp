#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(CardType type, const CardStats& stats){
    this->m_effect = type;
    this->m_stats=stats;
}

void Card::applyEncounter(Player& player) const{
    CardType const battle = CardType::Battle;
    CardType const buff = CardType::Buff;
    CardType const heal = CardType::Heal;
    CardType const treasure = CardType::Treasure;
    int cost = m_stats.cost;
    switch(m_effect){
        case battle:{
        int player_strength = player.getAttackStrength();
        int card_strength = m_stats.force;
        if(card_strength>player_strength){
            int HPLoss = m_stats.hpLossOnDefeat;
            player.damage(HPLoss);

        }
        else if(player_strength>=card_strength){
            int coins = m_stats.loot;
            player.levelUp();
            player.addCoins(coins);
        }
        break;}
        case buff:{
        int enforcing = m_stats.force;
        if(player.pay(cost)){
            player.buff(enforcing);
        }
        break;}
        case heal:{
        int healing = m_stats.heal;
        if(player.pay(cost)){
            player.heal(healing);
        }
        break;}
        case treasure:{
        int profit = m_stats.loot;
        player.addCoins(profit);
        break;}

    }
}

void printBattleCardInfo(const CardStats& card){
    cout<< "Card drawn: " << endl;
    cout<< "Type: Battle "<< endl;
    cout<<"Force: "<< card.force << endl;
    cout<< "Profit (on win): "<< card.loot<<endl;
    cout << "Damage taken (on loss): "<< card.hpLossOnDefeat<<endl;
}

void printBuffCardInfo(const CardStats& card){
    cout<< "Card drawn: " << endl;
    cout<< "Type: Buff "<< endl;
    cout<<"Cost: "<< card.cost << endl;
    cout<< "Buff: "<< card.buff<<endl;
}

void printHealCardInfo(const CardStats& card){
    cout<< "Card drawn: " << endl;
    cout<< "Type: Heal "<< endl;
    cout<<"Cost: "<< card.cost << endl;
    cout<< "Heal: "<< card.heal <<endl;
}

void printTreasureCardInfo(const CardStats& card){
    cout<< "Card drawn: " << endl;
    cout<< "Type: Treasure "<< endl;
    cout<<"Profit: "<< card.loot << endl;
}

void Card::printInfo() const{
    CardType const battle = CardType::Battle;
    CardType const buff = CardType::Buff;
    CardType const heal = CardType::Heal;
    CardType const treasure = CardType::Treasure;
    const CardStats& card = m_stats;
    switch(m_effect){
        case battle:{
            printBattleCardInfo(card);
            break;
        }
        case buff:{
            printBuffCardInfo(card);
            break;
        }
        case heal:{
            printHealCardInfo(card);
            break;
        }
        case treasure:{
            printTreasureCardInfo(card);
            break;
        }
        
    }
}