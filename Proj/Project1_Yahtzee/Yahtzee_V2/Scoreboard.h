 /* 
 * File:   Scoreboard.h
 * Author: Robert Duncan
 * Created on 24 April 2020, 11:44 AM
 * Purpose:  Scoreboard class
 */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <map>         //Maps
using namespace std;   //Standard Name-space under which System Libraries reside

class Score{
    private:
        map<int,int> sCard;     //Player's Scorecard
        //Upper Section
        int aces;       //Aces                                   [0-05]
        int twos;       //Twos                                   [0-10]
        int threes;     //Threes                                 [0-15]
        int fours;      //Fours                                  [0-20]
        int fives;      //Fives                                  [0-25]
        int sixes;      //Sixes                                  [0-30]
        int bonus;      //Aces+Twos+Threes+Fours+Fives+Sixes>=63 [0^35]
        //Lower Section
        int kind3;      //3 dice of same value                   [0-18]
        int kind4;      //4 dice of same value                   [0-24]
        int fHouse;     //3 dice same value, 2 dice same value   [0^25]
        int smallS;     //4 dice in sequential order             [0^30]
        int largeS;     //5 dice in sequential order             [0^40]
        int yaht;       //5 dice of same value                   [0^50]
        int chance;     //Add up all values of dice              [5-30]
        //Totals
        int upTtl;      //Total of upper section                 [0-140]
        int lowTtl;     //Total of lower section                 [5-217]
        int total;      //Total of upper+lower section           [5-357]
        //Check if already scored
        int numCatT;    //Number of categories including totals
        int numCat;     //Number of categories
        bool *scored;   //Array to check if category is scored
    public:
        Score();        //Default Constructor
        ~Score();       //Destructor
        //Set Functions (Upper)
        
        void setCat(int,int);   //Set score to correct category
        void setBonus();        //Determine if bonus is obtained
        void chkDice(int,int,int,int,int,int);
        int addDice(int,int,int,int,int,int);
        //Set Functions (Lower)
        void setKind3(int n){kind3=n;}
        void setKind4(int n){kind4=n;}
        void setFHouse(int n){fHouse=n;}
        void setSmallS(int n){smallS=n;}
        void setLargeS(int n){largeS=n;}
        void setYaht(int n){yaht=n;}
        void setChance(int n){chance=n;}
        //Set Functions (Total)
        void setUpTtl(){upTtl=aces+twos+threes+fours+fives+sixes+bonus;}
        void setLowTtl(){lowTtl=kind3+kind4+fHouse+smallS+largeS+yaht+chance;}
        void setTotal(){total=upTtl+lowTtl;}
        //Get Functions (Upper)
        int getAce()const{return aces;}
        int getTwo()const{return twos;}
        int getThree()const{return threes;}
        int getFour()const{return fours;}
        int getFive()const{return fives;}
        int getSix()const{return sixes;}
        int getBonus()const{return bonus;}
        //Get Functions (Lower)
        int getKind3()const{return kind3;}
        int getKind4()const{return kind4;}
        int getFHouse()const{return fHouse;}
        int getSmallS()const{return smallS;}
        int getLargeS()const{return largeS;}
        int getYaht()const{return yaht;}
        int getChance()const{return chance;}
        //Get Functions (Total)
        int getUpTtl()const{return upTtl;}
        int getLowTtl()const{return lowTtl;}
        int getTotal()const{return total;}
};

#endif /* SCOREBOARD_H */

