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
#include <stack>        //Stacks
#include <queue>        //Queue
#include <iomanip>      //Formatting
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries
#include "Dice.h"
#include "Scoreboard.h"

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void rolling(Dice [],char [],int);
void inScre(Dice [],Score &);
void scorecard(Score &);
void intro();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int NDICE=5;              //Number of dice
    Dice diceRll[NDICE]{6,6,6,6,6}; //Array of number of dice
    char svDie[NDICE]={0};          //Array to check if die is saved or not
    Score card;                     //Scorecard
    string rules;                   //Used to see intro to Yahtzee
    stack<int>preR1;                //Previous roll
    queue<int>preR2;                //Roll before previous roll
    
    //Prompt for intro
    cout<<"Would you like to read a quick intro of Yahtzee."<<endl;
    cout<<"Enter [yes] if so or [no] if not."<<endl;
    cin>>rules;
    if(rules=="yes")intro();
    
    //Start rolls
    rolling(diceRll,svDie,NDICE);
    
    //Input score
    inScre(diceRll,card);
    
    //Exit the program
    return 0;
}

void inScre(Dice diceRll[],Score &card){
    int input=0;    //To select the category 
    //Prompt for score input
    scorecard(card);    //Show the scorecard
    cout<<"Select which category you would like to score in from the "
            "table above."<<endl;
    cout<<"Enter the number in the brackets on the left to select."<<endl;
    cin>>input;
    
    //Input validation
    while(input<1||input>13||card.getChk(input-1)==true){
        //Input validation to make sure its a category
        if(input<1||input>13)cout<<"Input is out of the range of 1-13."<<endl;

        //Input validation to make sure a category isn't chosen twice
        if(card.getChk(input-1)==true)cout<<"Category has previously "
                "been chosen."<<endl;
        cout<<"Enter the number in the brackets on the left to select."<<endl;
        cin>>input;
    }
    
    //Input score into correct category
    //Check how many of each face was rolled
    card.chkDice(diceRll[0].getFace(),diceRll[1].getFace(),diceRll[2].getFace(),
            diceRll[3].getFace(),diceRll[4].getFace());
    card.inPoints(input-1);         //Input score into category
    //scorecard(card);                //Show the scorecard
}

void rolling(Dice diceRll[],char svDie[],int max){
    //Start rolling, starting roll=1,maximum number of rolls=3
    for(int roll=1,mxRoll=3;roll<=mxRoll;roll++){
        int count=0;    //Used to see if all dice saved
        cout<<"Rolling dice..."<<endl;
        cout<<"Roll "<<roll<<": "<<endl;
        for(int die=1;die<=max;die++){
            if(diceRll[die-1].getFace()==0)diceRll[die-1].roll();
            cout<<diceRll[die-1].getFace()<<" ";
        }
        cout<<endl;
    
        //Save dice or re-roll dice
        if(roll!=3){
            cout<<"Choose which dice to save. The remaining dice "
                    "will be re-rolled."<<endl;
            cout<<"Enter [y]es or [n]o in the order of dice "
                    "you want saved"<<endl;
            cin>>svDie[0]>>svDie[1]>>svDie[2]>>svDie[3]>>svDie[4];
            //Input validation
            while((svDie[0]!='y'&&svDie[0]!='n')||(svDie[1]!='y'&&svDie[1]!='n')
                    ||(svDie[2]!='y'&&svDie[2]!='n')||(svDie[3]!='y'&&
                    svDie[3]!='n')||(svDie[4]!='y'&&svDie[4]!='n')){
                cout<<"Invalid input. Input must be [y] or [n]. "
                        "Enter again."<<endl;
                cin>>svDie[0]>>svDie[1]>>svDie[2]>>svDie[3]>>svDie[4];
            } 
        }
        
        //If a die is not saved and not 3rd roll, then its value returns to 0
        for(int i=0;i<5;i++){
            if(svDie[i]!='y'&&roll!=3)diceRll[i].setFace(0); //Die not saved
        }
        
        //All Dice are saved, ends rolls
        for(int i=0;i<5;i++){
            if(svDie[i]=='y')count++;
            if(count==5)roll=3;
        }
    }
}

void scorecard(Score &card){
    //sCard[0-5]  upper section
    //sCard[6]    bonus
    //sCard[7-13] lower section
    //sCard[14]   upper total
    //sCard[15]   lower total
    //sCard[16]   grand total
    cout<<"Player 1's Card"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"      Upper Section      "<<endl;
    cout<<"-------------------------"<<endl;
    cout<<" [1] Aces           |"<<right<<setw(4)<<card.getCat(0)<<endl;
    cout<<" [2] Twos           |"<<setw(4)<<card.getCat(1)<<endl;
    cout<<" [3] Threes         |"<<setw(4)<<card.getCat(2)<<endl;
    cout<<" [4] Fours          |"<<setw(4)<<card.getCat(3)<<endl;
    cout<<" [5] Fives          |"<<setw(4)<<card.getCat(4)<<endl;
    cout<<" [6] Sixes          |"<<setw(4)<<card.getCat(5)<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Total               |"<<setw(4)<<card.getCat(14)-card.getCat(6)<<endl;
    cout<<"Bonus (total >= 63) |"<<setw(4)<<card.getCat(6)<<endl;
    cout<<"Total of upper half |"<<setw(4)<<card.getCat(14)<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"      Lower Section      "<<endl;
    cout<<"-------------------------"<<endl;
    cout<<" [7] 3 of a kind    |"<<setw(4)<<card.getCat(7)<<endl;
    cout<<" [8] 4 of a kind    |"<<setw(4)<<card.getCat(8)<<endl;
    cout<<" [9] Full house     |"<<setw(4)<<card.getCat(9)<<endl;
    cout<<"[10] Small straight |"<<setw(4)<<card.getCat(10)<<endl;
    cout<<"[11] Large straight |"<<setw(4)<<card.getCat(11)<<endl;
    cout<<"[12] Yahtzee        |"<<setw(4)<<card.getCat(12)<<endl;
    cout<<"[13] Chance         |"<<setw(4)<<card.getCat(13)<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Total of lower half |"<<setw(4)<<card.getCat(14)<<endl;
    cout<<"Total of upper half |"<<setw(4)<<card.getCat(15)<<endl;
    cout<<"Grand total         |"<<setw(4)<<card.getCat(16)<<endl;
    cout<<"-------------------------"<<endl;
}

void intro(){
    cout<<"The object of Yahtzee is to obtain the highest score "
            "from throwing 5 dice."<<endl;
    cout<<"The game consists of 13 rounds."<<endl;
    cout<<"In each round, you roll the dice and then score the roll in one of "
            "13 categories."<<endl;
    cout<<"You must score once in each category. The score is determined by "
            "a different rule for each category."<<endl;
    cout<<"You may only roll the dice a total of 3 times. After rolling 3 times "
            "you must choose a category to score."<<endl;
    cout<<"Once a box has been scored, it cannot be scored again "
            "for the rest of the game."<<endl;
    cout<<"The game ends once all 13 categories have been scored."<<endl;
}