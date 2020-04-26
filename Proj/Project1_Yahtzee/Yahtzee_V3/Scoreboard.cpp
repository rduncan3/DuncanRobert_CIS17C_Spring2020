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
    try{
        scored=new bool[numCat];
        for(int i=0;i<numCat;i++){
            scored[i]=false;
        }
        chkVal=new int[6];
        for(int i=0;i<6;i++){
            chkVal[i]=0;
        }
    }
    catch(bad_alloc){
        memEr();
    }
}

Score::~Score(){
    delete []scored;
    delete []chkVal;
}

void Score::resetDice(){
    for(int i=0;i<6;i++){
        chkVal[i]=0;
    }
}

int Score::mode(int num){
    int points=0;   //Points to return
    int cnt=0;      //Count chkValues
    for(int k=0;k<6;k++){
        if(chkVal[k]>=num)cnt=num;
    }
    if(cnt>=num){
        for(int i=0,j=1;i<6;i++,j++){
            points+=chkVal[i]*j;
        }
    }
    return points;
}

int Score::fHouse(){
    int points=25;  //25 Points if full house
        for(int i=0;i<6;i++){
            if(chkVal[i]==1||chkVal[i]==4||chkVal[i]==5||chkVal[i]==6)points=0;
        }
    return points;
}

int Score::straight(int n){
    int points=0;   //Points to return
    int count=0;    //Count values
    if(n==4){
        points=30;
        if(chkVal[0]>=1&&chkVal[1]>=1&&chkVal[2]>=1&&chkVal[3]>=1);         //1234
        else if(chkVal[1]>=1&&chkVal[2]>=1&&chkVal[3]>=1&&chkVal[4]>=1);    //2345
        else if(chkVal[2]>=1&&chkVal[3]>=1&&chkVal[4]>=1&&chkVal[5]>=1);    //3456
        else points=0;
    }
    else if(n==5){
        points=40;
        if(chkVal[0]==1&&chkVal[1]==1&&chkVal[2]==1&&chkVal[3]==1&&chkVal[4]==1);      //12345
        else if(chkVal[1]==1&&chkVal[2]==1&&chkVal[3]==1&&chkVal[4]==1&&chkVal[5]==1); //23456
        else points=0;
    }
    return points;
}

int Score::yahtzee(){
    int points=50;  //Number of points possible
        for(int i=0;i<6;i++){
            //If any amount is not 5 or 0, points are 0;
            if(chkVal[i]<5&&chkVal[i]>=1)points=0;    
        }
    return points;
}

int Score::chance(){
    int points=0;   //Points to earn
    for(int i=0,j=1;i<5;i++,j++){
        points+=chkVal[i]*j;
    }
    return points;
}

void Score::inPoints(int cat){
    switch (cat){
        case 0:
        case 1:setCat(cat,chkVal[0]*1);break;
        case 2:setCat(cat,chkVal[1]*2);break;
        case 3:setCat(cat,chkVal[2]*3);break;
        case 4:setCat(cat,chkVal[3]*4);break;
        case 5:setCat(cat,chkVal[4]*5);break;
        case 6:setCat(cat,chkVal[5]*6);break;
        case 7:setCat(cat,mode(3));break;
        case 8:setCat(cat,mode(4));break;
        case 9:setCat(cat,fHouse());break;
        case 10:setCat(cat,straight(4));break;
        case 11:setCat(cat,straight(5));break;
        case 12:setCat(cat,yahtzee());break;
        case 13:setCat(cat,chance());break;
    }
}

void Score::totals(){
    //sCard[0-5]  upper section
    //sCard[6]    bonus
    //sCard[7-13] lower section
    //sCard[14]   upper total
    //sCard[15]   lower total
    //sCard[16]   grand total
    sCard[14]=sCard[15]=sCard[16]=0;  //Used to reset points when generating new score cards
    //Total of upper section
    for(int i=0;i<=5;i++){
        sCard[14]+=sCard[i];    //Add upper section
    }
    setBonus();//+35 points if bonus condition is met
    //Total of lower section
    for(int i=7;i<=13;i++){
        sCard[15]+=sCard[i];    //Add lower section
    }
    //Total of both sections
    sCard[16]=sCard[14]+sCard[15];  //Add upper + lower to get grand total
}

void Score::setCat(int cat,int val){
    sCard.find(cat);        //Use key to find correct category
    if(scored[cat]==false){ //If category has not been scored into yet
        sCard[cat]=val;     //Enter score for that category
        scored[cat]=true;   //Category is now scored
    }
}

void Score::setBonus(){
    if(sCard[14]>=63){
        sCard[6]=35;
        sCard[14]+=35;
    }
}

int Score::getCat(int cat){
    sCard.find(cat);        //Use key to find correct category
    return sCard[cat];
}

bool Score::getChk(int cat) const{
    return scored[cat];
}

void Score::chkDice(int d1, int d2, int d3, int d4, int d5){
    //Check how many of each face was rolled
    //Check die 1
    if     (d1==1)chkVal[0]++;
    else if(d1==2)chkVal[1]++;
    else if(d1==3)chkVal[2]++;
    else if(d1==4)chkVal[3]++;
    else if(d1==5)chkVal[4]++;
    else if(d1==6)chkVal[5]++;
    //Check die 2
    if     (d2==1)chkVal[0]++;
    else if(d2==2)chkVal[1]++;
    else if(d2==3)chkVal[2]++;
    else if(d2==4)chkVal[3]++;
    else if(d2==5)chkVal[4]++;
    else if(d2==6)chkVal[5]++;
    //Check die 3
    if     (d3==1)chkVal[0]++;
    else if(d3==2)chkVal[1]++;
    else if(d3==3)chkVal[2]++;
    else if(d3==4)chkVal[3]++;
    else if(d3==5)chkVal[4]++;
    else if(d3==6)chkVal[5]++;
    //Check die 4
    if     (d4==1)chkVal[0]++;
    else if(d4==2)chkVal[1]++;
    else if(d4==3)chkVal[2]++;
    else if(d4==4)chkVal[3]++;
    else if(d4==5)chkVal[4]++;
    else if(d4==6)chkVal[5]++;
    //Check die 5
    if     (d5==1)chkVal[0]++;
    else if(d5==2)chkVal[1]++;
    else if(d5==3)chkVal[2]++;
    else if(d5==4)chkVal[3]++;
    else if(d5==5)chkVal[4]++;
    else if(d5==6)chkVal[5]++;
}

void Score::memEr(){
    cout<<"ERROR: Cannot allocate memory."<<endl;
    throw (EXIT_FAILURE);
}