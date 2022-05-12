#include <iostream>
#ifndef EX2_CARD
#define EX2_CARD
#include "Card.h"
#include "Player.h"
#include "utilities.h"
using namespace std;

Card::Card(CardType type, const CardStats& stats) :

    m_effect(type),
    m_stats(stats)
    {

    }

void Card::applyEncounter(Player& player) const{
    CardType const battle = CardType::Battle;
    CardType const buff = CardType::Buff;
    CardType const heal = CardType::Heal;
    CardType const treasure = CardType::Treasure;
    int cost = m_stats.cost;
    bool isWin=true;
    switch(m_effect){
        case battle:{
        int player_strength = player.getAttackStrength();
        int card_strength = m_stats.force;
        if(card_strength>player_strength){
            isWin = false;
            int HPLoss = m_stats.hpLossOnDefeat;
            player.damage(HPLoss);
            printBattleResult(isWin);

        }
        else if(player_strength>=card_strength){
            int coins = m_stats.loot;
            player.levelUp();
            player.addCoins(coins);
            printBattleResult(isWin);
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

#endif