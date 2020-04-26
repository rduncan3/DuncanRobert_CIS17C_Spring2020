 /* 
 * File:   Scoreboard.h
 * Author: Robert Duncan
 * Created on 24 April 2020, 12:38 PM
 * Purpose:  Scoreboard class
 */

#include "Scoreboard.h"

Score::Score(){
    numCatT=17; //Set number of categories including totals
    numCat=13;  //Set number of categories
    for(int i=0;i<numCatT;i++){
        sCard.insert(pair<int,int>(i,0));
    }
    //Allocate memory
    scored=new bool[numCat];
    for(int i=0;i<numCat;i++){
        scored[i]=0;
    }
}

Score::~Score(){
    delete []scored;
}

void Score::chkDice(int d1, int d2, int d3, int d4, int d5, int n){
    int cat=n-1;    //Determines which category was inputed
    int points=0;   //How many points will be earned
    //Check which category
    if(cat==0&&scored[cat]==0){             //Aces
        points=addDice(d1,d2,d3,d4,d5,1);   //Calculate points for Aces
        setCat(cat,points);                 //Input points
    } 
    else if(cat==1&&scored[cat]==0){        //Twos
        points=addDice(d1,d2,d3,d4,d5,2);   //Calculate points for Twos
        setCat(cat,points);                 //Input points
    }
    else if(cat==2&&scored[cat]==0){        //Threes
        points=addDice(d1,d2,d3,d4,d5,3);   //Calculate points for Threes
        setCat(cat,points);                 //Input points
    }
    else if(cat==3&&scored[cat]==0){        //Fours
        points=addDice(d1,d2,d3,d4,d5,4);   //Calculate points for Fours
        setCat(cat,points);                 //Input points
    }
    else if(cat==4&&scored[cat]==0){        //Fives
        points=addDice(d1,d2,d3,d4,d5,5);   //Calculate points for Fours
        setCat(cat,points);                 //Input points
    }
    else if(cat==5&&scored[cat]==0){        //Sixes
        points=addDice(d1,d2,d3,d4,d5,6);   //Calculate points for Sixes
        setCat(cat,points);                 //Input points
    }
    else if(cat==6&&scored[cat]==0){        //Three of a kind
        
    }
}

int Score::addDice(int d1, int d2, int d3, int d4, int d5, int val){
    int points=0;
    if(d1==val)points+=val;
    if(d2==val)points+=val;
    if(d3==val)points+=val;
    if(d4==val)points+=val;
    if(d5==val)points+=val;
    return points;
}

void Score::setCat(int cat,int val){
    sCard.find(cat);        //Use key to find correct category
    if(scored[cat]==0){     //If category has not been scored into yet
        sCard[cat]=val;     //Enter score for that category
        scored[cat]=1;      //Category is now scored
    }
}

void Score::setBonus(){
    if(sCard[14]>=63){
        sCard[6]=35;
    }
}

void Score::setUpTtl(){
    
}