#include "Mtmchkin.h"
using namespace std;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards){
    this->player::name = playerName;
    this->card = cardsArray;
    this->numOfCards=numOfCards;


}


GameStatus Mtmchkin::getGameStatus() const{
    return status;
}

void Mtmchkin::playNextCard(){
    Card playingCard = card[currCard];
    playingCard.printInfo();





    if(currCard == numOfCards-1){
        currCard = 0
    }
    else{
        currCard ++;
    }

}

bool Mtmchkin::isOver() const{
    
    return(this->player.getLevel() >= 10 || player.isKnockedOut());
}



