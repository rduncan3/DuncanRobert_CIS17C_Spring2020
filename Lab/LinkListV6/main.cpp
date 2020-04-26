/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   Sept 24th, 2019
 * Purpose:Exploration of a Linked List
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Link.h"
#include "List.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    List list(10);
    
    //Initialize Variables
    list.prntLnk();
    
    //Process inputs to outputs/map
    
    //Display the results
    cout<<"Size of the list = "<<list.lstSize()<<endl;
    int val;
    cout<<"Testing popping a value from the front"<<endl;
    list.popFrt(val);
    cout<<"Value from the front = "<<val<<endl;
    list.prntLnk();
    cout<<"Size of the list = "<<list.lstSize()<<endl;
    /*
    cout<<"Testing popping a value from the back"<<endl;
    list=popBck(list,val);
    cout<<"Value from the Back = "<<val<<endl;
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    cout<<"Testing pushing a value from the back"<<endl;
    list=pushBck(list,7);
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    cout<<"Testing pushing a value from the front"<<endl;
    list=pushFrt(list,24);
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    //Clean up 
    destroy(list);
    */
    //Exit stage right
    return 0;
}