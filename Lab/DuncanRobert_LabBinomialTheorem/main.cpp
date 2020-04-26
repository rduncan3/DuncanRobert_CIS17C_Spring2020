/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 16 October 2019, 2:47 PM
 * Purpose:  Binomial Theorem
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cmath>
#include <cstdlib>      //Srand to set the seed
#include <ctime>        //Time for rand
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants
const int PERCENT=100;

//Function Prototypes
int factorial(int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float prob=0,nCr=0,probHead=0,probTail=0,nHeads=0,nHeadsPos=0,coinFlip=0;
    int coin1=0,coin2=0,coin3=0,coin4=0,test=0;
    
    //Input Data/Variables
    coinFlip=10000;
    nHeads=3;
    nHeadsPos=4;
    probHead=probTail=0.5;
    nCr=factorial(nHeadsPos)/(factorial(nHeadsPos-nHeads)*factorial(nHeads));
    prob=nCr*pow(probTail,4-nHeads)*pow(probHead,nHeads)*PERCENT;
    
    //Process or map the inputs to the outputs
    //Fair coin flip
    for(int i=0;i<coinFlip;i++){
        //head=0,tails=1;
        coin1=rand()%2;
        coin2=rand()%2;
        coin3=rand()%2;
        coin4=rand()%2;
        if(coin1+coin2+coin3+coin4<=1)test++;
    }
    //Coin with 60% chance of head flip
    
    //Display/Output all pertinent variables
    cout<<"Calculation:"<<endl;
    cout<<" Probability of 4 coins and getting 1 tail and 3 heads: "<<prob<<"%"<<endl;
    cout<<"Simulation:"<<endl;
    cout<<" Flipping 4 fair coins 10000 times..."<<endl;
    cout<<" Amount of times there were 3 heads and 1 tails: "<<test<<endl;
    cout<<" Probability: "<<test/coinFlip*PERCENT<<"%"<<endl;
    
    probHead=0.6;
    probTail=0.4;
    prob=nCr*pow(probTail,4-nHeads)*pow(probHead,nHeads)*PERCENT;
    
    for(int i=0;i<coinFlip;i++){
        //head=0,1,2; tails=3,4;
        coin1=rand()%5;
        coin2=rand()%5;
        coin3=rand()%5;
        coin4=rand()%5;
        if(coin1<=2)coin1=0;
        else coin1=1;
        if(coin2<=2)coin1=0;
        else coin1=2;
        if(coin3<=2)coin1=0;
        else coin1=3;
        if(coin4<=2)coin1=0;
        else coin1=4;
        if(coin1+coin2+coin3+coin4<=1)test++;
    }
    
    cout<<"Calculation:"<<endl;
    cout<<" Probability of flipping 4 coins with 60% more chance of landing "
            "heads and getting 1 tail and 3 heads: "<<prob<<"%"<<endl;
    cout<<"Simulation:"<<endl;
    cout<<" Flipping 4 fair coins 10000 times..."<<endl;
    cout<<" Amount of times there were 3 heads and 1 tails: "<<test<<endl;
    cout<<" Probability: "<<test/coinFlip*PERCENT<<"%"<<endl;
    
    
    //Exit the program
    return 0;
}

int factorial(int num){
    int temp=1;
    for(int i=1;i<=num;i++){
        temp*=i;
    }
    return temp;
}