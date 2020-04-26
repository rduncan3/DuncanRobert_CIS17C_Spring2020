/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 22 April 2019, 10:25 AM
 * Purpose:  Yahtzee V1
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cstdlib>      //Srand to set the seed
#include <ctime>        //Time for rand
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries
#include "Dice.h"

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int NDICE=5;              //Number of dice
    Dice dice[NDICE]{6,6,6,6,6};    //Array of number of dice
    //Test functions
    for(int i=0;i<NDICE;i++){
        cout<<dice[i].roll()<<" ";
    }
    cout<<endl;
    cout<<dice[0].getFace()<<endl;
    cout<<"        "<<dice[4].getFace()<<endl;
    cout<<"    "<<dice[2].getFace()<<endl;
    
    //Initialize Variables
    
    //Input Data/Variables
    
    //Process or map the inputs to the outputs
    
    //Display/Output all pertinent variables
    
    //Exit the program
    return 0;
}