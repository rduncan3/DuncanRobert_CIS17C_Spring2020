 /* 
 * File:   Scoreboard.h
 * Author: Robert Duncan
 * Created on 24 April 2020, 11:44 AM
 * Purpose:  Scoreboard class
 */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>     //Input/Output Stream Library
#include <new>
using namespace std;   //Standard Name-space under which System Libraries reside
#include <map>         //Maps

class Score{
    private:
        map<int,int> sCard;     //Player's Scorecard
        //The amount of each roll
        int *chkVal;            //Used to check how many of each value is rolled
        //Check if already scored
        int numCatT;            //Number of categories including totals
        int numCat;             //Number of categories
        bool *scored;           //Array to check if category is scored
    public:
        Score();        //Default Constructor
        ~Score();       //Destructor
        void setCat(int,int);   //Set score to correct category
        void setBonus();        //Determine if bonus is obtained
        void chkDice(int,int,int,int,int);  //Check how many of each face is rolled
        void resetDice();                   //Reset array to 0
        void inPoints(int);                 //Points into categories
        //Functions to help with lower section of card
        int mode(int);                //Find mode for three/four of a kind
        int fHouse();                 //Find full house
        int straight(int);            //Find small/large straight
        int yahtzee();                //Find Yahtzee
        int chance();                 //Find chance
        //Get totals
        void totals();
        int getCat(int);
        bool getChk(int)const;
        void memEr();                       //Error allocating memory
};
#endif /* SCOREBOARD_H */