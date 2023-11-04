//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

//evaluate hand function takes in dealer card and determines what action player should take

Choice Hand::evaluateHand( Card dealerCard ) const
{
    //initializing player hand value and dealer card for easy access
    int val = mCard1.getValue() + mCard2.getValue();
    int val2 = dealerCard.getValue();
    
    //general rule for double ace
    if (mCard1.getFace() == Face::ACE && mCard2.getFace() == Face::ACE){
        return(Choice::SPLIT);
    }
    
    //general rule for double ten
    if (mCard1.getFace() == Face::TEN && mCard2.getFace() == Face::TEN){
        return(Choice::STAND);
    }
    
    //for dealer card deuce
    if (val2 == 2){
        //for all aces on the chart
        if (Hand::isPair()){
            if (val == 8){
                return (Choice::HIT);
            }
        
            
            else if (val == 4 || val == 6 || val == 12){
                return (Choice::SPLITHIT);
            }
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            else{
                return (Choice::SPLIT);
            }
            
            
        }
        
        //for all aces
        else if (Hand::isSoft()){
            if (val <= 7){
                return (Choice::HIT);
            }
            else{
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        
        else {
            if (val == 8 || val == 9 || val == 12){
                return (Choice::HIT);
            }
            else if (val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else {
                return (Choice::STAND);
            }
        }

        
    }
        

    //for dealer card 3
    if (val2 == 3){
        if (Hand::isPair()){
            if (val == 8){
                return (Choice::HIT);
            }
            
            
            else if (val == 4 || val == 6){
                return (Choice::SPLITHIT);
            }
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            else{
                return (Choice::SPLIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val <= 6){
                return (Choice::HIT);
            }
            else if (val == 7){
                return(Choice::DOUBLEHIT);
            }
            
            else if (val == 8){
                return(Choice::DOUBLESTAND);
            }
            else
            {
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 8 || val == 12){
                return (Choice::HIT);
            }
            else if (val == 9 || val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else {
                return (Choice::STAND);
            }
        }
        
        
        
    }
    //for dealer card 4
    if (val2 == 4){
        //for all pairs
        if (Hand::isPair()){
            if (val == 8){
                return (Choice::HIT);
            }
            
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            else{
                return (Choice::SPLIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val <= 4){
                return (Choice::HIT);
            }
            else if (val == 7 || val == 6 || val == 5){
                return(Choice::DOUBLEHIT);
            }
            
            else if (val == 8){
                return(Choice::DOUBLESTAND);
            }
            else
            {
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 8){
                return (Choice::HIT);
            }
            else if (val == 9 || val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else {
                return (Choice::STAND);
            }
        }
        
        
        
    }
    //for dealer card 5
    if (val2 == 5){
        //for all pairs
        if (Hand::isPair()){
            if (val == 8){
                return (Choice::SPLITHIT);
            }
            
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            else{
                return (Choice::SPLIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val == 9){
                return (Choice::STAND);
            }
            
            else if (val == 8){
                return(Choice::DOUBLESTAND);
            }
            else
            {
                return(Choice::DOUBLEHIT);
            }
        }
        //for all non-pairs or aces on the chart
            
        else {
            if (val == 8){
                return (Choice::HIT);
            }
            else if (val == 9 || val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else {
                return (Choice::STAND);
            }
        }
        
        
    }
    //for dealer card 6
    if (val2 == 6){
        if (Hand::isPair()){
            //for all pairs
            if (val == 8){
                return (Choice::SPLITHIT);
            }
            
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            else{
                return (Choice::SPLIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val == 9){
                return (Choice::STAND);
            }
            
            else if (val == 8){
                return(Choice::DOUBLESTAND);
            }
            else
            {
                return(Choice::DOUBLEHIT);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 8){
                return (Choice::HIT);
            }
            else if (val == 9 || val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else {
                return (Choice::STAND);
            }
        }
        
        
        
    }
    //for dealer card 7
    if (val2 == 7){
        //for all pairs
        if (Hand::isPair()){
            if (val == 8 || val == 12){
                return (Choice::HIT);
            }
            
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            else if (val == 18){
                return (Choice::STAND);
            }
            
            else{
                return (Choice::SPLIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val <= 7){
                return (Choice::HIT);
            }
            
            else
            {
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 17){
                return (Choice::STAND);
            }
            else if ( val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else {
                return (Choice::HIT);
            }
        }
        
        
        
        
    }
    //for dealer card 8
    if (val2 == 8){
        //for all pairs
        if (Hand::isPair()){
            if (val == 16 || val == 18){
                return (Choice::SPLIT);
            }
            
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            
            else{
                return (Choice::HIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val <= 7){
                return (Choice::HIT);
            }
            
            else
            {
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 17){
                return (Choice::STAND);
            }
            else if ( val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else {
                return (Choice::HIT);
            }
        }
        
        
        
    }
    //for dealer card 9
    if (val2 == 9){
        //for all pairs
        if (Hand::isPair()){
            if (val == 16 || val == 18){
                return (Choice::SPLIT);
            }
            
            
            else if (val == 10){
                return (Choice::DOUBLEHIT);
            }
            
            
            else{
                return (Choice::HIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val <= 8){
                return (Choice::HIT);
            }
            
            else
            {
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 17){
                return (Choice::STAND);
            }
            else if ( val == 10 || val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else if (val == 16){
                return(Choice::SURRENDERHIT);
            }
            else {
                return (Choice::HIT);
            }
        }
        
        
        
    }
    //for dealer card 10
    if (val2 == 10){
        //for all pairs
        if (Hand::isPair()){
            if (val == 16){
                return (Choice::SPLIT);
            }
            
            
            else if (val == 18){
                return (Choice::STAND);
            }
            
            
            else{
                return (Choice::HIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val <= 8){
                return (Choice::HIT);
            }
            
            else
            {
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 17){
                return (Choice::STAND);
            }
            else if ( val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else if (val == 16 || val == 15){
                return(Choice::SURRENDERHIT);
            }
            else {
                return (Choice::HIT);
            }
        }
        
        
    }

    //for dealer card ace
    if (val2 == 1){
        //for all pairs
        if (Hand::isPair()){
            if (val == 16){
                return (Choice::SPLIT);
            }
            
            
            else if (val == 18){
                return (Choice::STAND);
            }
            
            
            else{
                return (Choice::HIT);
            }
            
            
        }
        //for all aces

        else if (Hand::isSoft()){
            if (val <= 8){
                return (Choice::HIT);
            }
            
            else
            {
                return(Choice::STAND);
            }
        }
        //for all non-pairs or aces on the chart
        else {
            if (val == 17){
                return (Choice::STAND);
            }
            else if ( val == 11){
                return(Choice::DOUBLEHIT);
                
            }
            else if (val == 16){
                return(Choice::SURRENDERHIT);
            }
            else {
                return (Choice::HIT);
            }
        }
        
    }
   
    
 
    
    
    
    
    
    
    // by default STAND
    
    Choice c = Choice::STAND;
    return( c );
}

    
//check if it is a pair
bool Hand::isPair() const
{
    if (mCard1.getFace() == mCard2.getFace()){
        return (true);
    }
    return( false );
}

//check if either card is an ace
bool Hand::isSoft() const
{
    if (mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE){
        return(true);
    }
    return( false );
}



}
