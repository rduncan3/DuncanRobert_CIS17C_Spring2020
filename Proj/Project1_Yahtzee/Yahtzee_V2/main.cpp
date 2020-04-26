/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 22 April 2019, 12:05 PM
 * Purpose:  Yahtzee V2
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cstdlib>      //Srand to set the seed
#include <ctime>        //Time for rand
#include <list>         //For lists
#include <map>          //For map
//#include <iterator>     //For iterators
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries
#include "Dice.h"
#include "Scoreboard.h"

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    Score card;
    /*
    const int NDICE=5;              //Number of dice
    Dice dice[NDICE]{6,6,6,6,6};    //Array of number of dice
    Score card;                     //Scorecard
    char save[NDICE];               //Used to determine if dice saved
    
    //Start Turn
    
    cout<<"Rolling Dice..."<<endl;
    for(int i=0;i<NDICE;i++){
        dice[i].roll();
        cout<<dice[i].getFace()<<" ";
    }
    cout<<endl;
    */
    
    //Exit the program
    return 0;
}