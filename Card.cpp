#include "Card.h"
#include "utilities.h"


Card::Card(CardType type, const CardStats& stats){
    this->m_effect = type;
    this->m_stats=stats;
}

void Card::applyEncounter(Player& player) const{
    switch(m_effect){
        case CardType Battle:
        int player_strength = player.getAttackStrength();
        int card_strength = m_stats->force;
        if(card_strength>player_strength){
            int HPLoss = m_stats->hpLossOnDefeat;
            player.damage(HPLoss);

        }
        else if(player_strength>=card_strength){
            int coins = m_stats->loot;
            player.levelUp();
            player.addCoins(coins);
        }
        break;
        case CardType::Buff:
        int enforcing = m_stats->force;
        int cost = m_stats->cost;
        if(player.pay(cost)){
            player.buff(enforcing);
        }
        break;
        case CardType::Heal:
        int healing = m_stats->heal;
        int cost = m_stats->cost;
        if(player.pay(cost)){
            player.heal(healing);
        }
        break;
        case CardType::Treasure:
        int profit = m_stats->loot;
        player.addCoins(profit);
        break;

    }
}
