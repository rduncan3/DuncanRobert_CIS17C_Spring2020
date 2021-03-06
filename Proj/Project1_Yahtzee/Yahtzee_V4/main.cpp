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
#include <list>         //Lists
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries
#include "Dice.h"
#include "Scoreboard.h"

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void rolling(Dice [],char [],int);
void inScre(Dice [],Score &,string,list<int> &);
void scorecard(Score &,string,list<int> &);
void cardUp(Score &,list<int>&);
void cardLw(Score &,list<int> &);
void intro();
void showlist(list<int>);

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
    string lName="";                //Local variable for player's name
    list<int> prvScrd;              //Previously used categories
    
    /*
    //Prompt for intro
    cout<<"Would you like to read a quick intro of Yahtzee."<<endl;
    cout<<"Enter [yes] if so or [no] if not."<<endl;
    cin>>rules;
    if(rules=="yes")intro();
    */
    
    //Name of player
    cout<<"Enter your name"<<endl;
    cin>>lName;
    
    //Start Playing
    for(int round=1,mxRound=13;round<=mxRound;round++){
        cout<<lName;
        cout<<" | Round "<<round<<endl;
        rolling(diceRll,svDie,NDICE);//Start rolls
        inScre(diceRll,card,lName,prvScrd); //Input score
    }
    
    //Exit the program
    return 0;
}

void inScre(Dice diceRll[],Score &card, string lName,list<int> &prvScrd){
    int input=0;    //To select the category 
    //Prompt for score input
    scorecard(card,lName,prvScrd);    //Show the scorecard
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
    //card.chkDice(6,6,1,5,5);    //Use for specific testing
    card.inPoints(input);         //Input score into category
    prvScrd.push_front(input);    //Category chosen goes into list
    scorecard(card,lName,prvScrd);              //Show the scorecard
    
    //Reset Rolls
    for(int i=0;i<5;i++){
        diceRll[i].setFace(0);
    }
    card.resetDice();
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

void cardUp(Score &card,list<int> &prvScrd){
    cout<<"-------------------------"<<endl;
    cout<<"      Upper Section      "<<endl;
    cout<<"-------------------------"<<endl;
    //Aces
    if(card.getChk(0)==false){
        cout<<" [1] Aces           |"<<right<<setw(4)<<card.getCat(0)<<endl;
    }
    else cout<<" [X] Aces           |"<<right<<setw(4)<<card.getCat(0)<<endl;
    //Twos
    if(card.getCat(1)==false){
        cout<<" [2] Twos           |"<<setw(4)<<card.getCat(1)<<endl;
    }
    else cout<<" [X] Twos           |"<<setw(4)<<card.getCat(1)<<endl;
    //Threes
    if(card.getCat(2)==false){
        cout<<" [3] Threes         |"<<setw(4)<<card.getCat(2)<<endl;
    }
    else cout<<" [X] Threes         |"<<setw(4)<<card.getCat(2)<<endl;
    //Fours
    if(card.getCat(3)==false){
        cout<<" [4] Fours          |"<<setw(4)<<card.getCat(3)<<endl;
    }
    else cout<<" [X] Fours          |"<<setw(4)<<card.getCat(3)<<endl;
    //Fives
    if(card.getCat(4)==false){
        cout<<" [5] Fives          |"<<setw(4)<<card.getCat(4)<<endl;
    }
    else cout<<" [X] Fives          |"<<setw(4)<<card.getCat(4)<<endl;
    //Sixes
    if(card.getCat(5)==false){
        cout<<" [6] Sixes          |"<<setw(4)<<card.getCat(5)<<endl;
    }
    else cout<<" [X] Sixes          |"<<setw(4)<<card.getCat(5)<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Total               |"<<setw(4)<<card.getCat(14)-card.getCat(6)<<endl;
    cout<<"Bonus (total >= 63) |"<<setw(4)<<card.getCat(6)<<endl;
    cout<<"Total of upper half |"<<setw(4)<<card.getCat(14)<<endl;
}

void cardLW(Score &card,list<int> &prvScrd){
    cout<<"-------------------------"<<endl;
    cout<<"      Lower Section      "<<endl;
    cout<<"-------------------------"<<endl;
    //Three of a kind
    if(card.getCat(7)==false){
        cout<<" [7] 3 of a kind    |"<<setw(4)<<card.getCat(7)<<endl;
    }
    else cout<<" [X] 3 of a kind    |"<<setw(4)<<card.getCat(7)<<endl;
    //Four of a kind
    if(card.getCat(8)==false){
        cout<<" [8] 4 of a kind    |"<<setw(4)<<card.getCat(8)<<endl;
    }
    else cout<<" [X] 4 of a kind    |"<<setw(4)<<card.getCat(8)<<endl;
    //Full house
    if(card.getCat(9)==false){
        cout<<" [9] Full house     |"<<setw(4)<<card.getCat(9)<<endl;
    }
    else cout<<" [X] Full house     |"<<setw(4)<<card.getCat(9)<<endl;
    //Small straight
    if(card.getCat(10)==false){
        cout<<"[10] Small straight |"<<setw(4)<<card.getCat(10)<<endl;
    }
    else cout<<" [X] Small straight |"<<setw(4)<<card.getCat(10)<<endl;
    //Large straight
    if(card.getCat(11)==false){
        cout<<"[11] Large straight |"<<setw(4)<<card.getCat(11)<<endl;
    }
    else cout<<" [X] Large straight |"<<setw(4)<<card.getCat(11)<<endl;
    //Yahtzee
    if(card.getCat(12)==false){
        cout<<"[12] Yahtzee        |"<<setw(4)<<card.getCat(12)<<endl;
    }
    else cout<<" [X] Yahtzee        |"<<setw(4)<<card.getCat(12)<<endl;
    //Chance
    if(card.getCat(13)==false){
        cout<<"[13] Chance         |"<<setw(4)<<card.getCat(13)<<endl;
    }
    else cout<<" [X] Chance         |"<<setw(4)<<card.getCat(13)<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Total of lower half |"<<setw(4)<<card.getCat(14)<<endl;
    cout<<"Total of upper half |"<<setw(4)<<card.getCat(15)<<endl;
    cout<<"Grand total         |"<<setw(4)<<card.getCat(16)<<endl;
}

void scorecard(Score &card, string lName,list<int> &prvScrd){
    //sCard[0-5]  upper section
    //sCard[6]    bonus
    //sCard[7-13] lower section
    //sCard[14]   upper total
    //sCard[15]   lower total
    //sCard[16]   grand total
    cout<<lName<<"'s Card"<<endl;
    cardUp(card,prvScrd);   //Upper scorecard
    cardLW(card,prvScrd);   //Lower scorecard
    cout<<"-------------------------"<<endl;
    cout<<"Categories already chosen|"<<endl;
    prvScrd.sort();         //Sort chosen categories
    showlist(prvScrd);      //Output chosen categories
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

//https://www.geeksforgeeks.org/list-cpp-stl/
void showlist(list <int> g){ 
    list <int> :: iterator it; 
    for(it=g.begin();it!=g.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
} 