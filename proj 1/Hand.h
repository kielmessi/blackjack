//
//  Hand.h
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Enums.h"

namespace cs32
{

// this class represents an opening blackjack player hand of
// two cards
// although this class builds and runs, various TODO operations
// need to be completed by CS 32 students
class Hand
{
public:
    Hand( Card card1, Card card2 );
    // getters for the Card fields of this class
    Card getCard1() const;
    Card getCard2() const;
    


    Choice evaluateHand( Card dealerCard ) const;
    

    bool isPair() const;

    bool isSoft() const;
private:
    // the data members of each Hand class
    Card mCard1, mCard2;
};


}


#endif
