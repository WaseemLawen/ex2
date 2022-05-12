
#ifndef EX2_MTMCHKIN
#define EX2_MTMCHKIN
#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"

using namespace std;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :

    m_playerName(playerName),
    m_player(Player(playerName)),
    m_cardArr(new Card[numOfCards]),
    m_status(GameStatus:: MidGame),
    m_numOfCards(numOfCards),
    m_currCard(0)
    
{
    for (int i=0; i<numOfCards; i++){
        m_cardArr[i] = cardsArray[i];
    }
}

Mtmchkin::~Mtmchkin(){
    delete[] m_cardArr;
}

Mtmchkin::Mtmchkin(const Mtmchkin& game):
    m_playerName(game.m_playerName),
    m_player(Player(game.m_playerName)),
    m_cardArr(new Card[game.m_numOfCards]),
    m_status(GameStatus:: MidGame),
    m_numOfCards(game.m_numOfCards),
    m_currCard(0)
{
    for (int i=0; i<m_numOfCards; i++){
        m_cardArr[i] = game.m_cardArr[i];
    }
}

Mtmchkin& Mtmchkin :: operator=(const Mtmchkin& other){
    if(this==&other){
        return *this;
    }
    else{
        delete[] m_cardArr;
        m_playerName = other.m_playerName;
        m_player = other.m_player;
        m_cardArr = new Card[m_numOfCards];
        m_status = other.m_status;
        m_numOfCards = other.m_numOfCards;
        m_currCard = other.m_currCard;

        for(int i=0; i<m_numOfCards; i++){
            m_cardArr[i] = other.m_cardArr[i];
        }
    }
  
    return *this;

}

GameStatus Mtmchkin::getGameStatus() const{
    return m_status;
}

void Mtmchkin::playNextCard(){
    Card playingCard = m_cardArr[m_currCard];
    playingCard.printInfo();
    playingCard.applyEncounter(m_player);
    m_player.printInfo();

    if(m_currCard == m_numOfCards-1){
        m_currCard = 0;
    }
    else{
        m_currCard ++;
    }
    if(m_player.getLevel()==10){
        m_status = GameStatus:: Win;
    }
    if(m_player.isKnockedOut()){
        m_status = GameStatus :: Loss;
    }

}

bool Mtmchkin::isOver() const {
    if(m_status == GameStatus::Win || m_status == GameStatus::Loss){
        return true;
    }
    return false;
}

#endif

