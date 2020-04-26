/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 11 October 2019, 12:23 PM
 * Purpose:  Lists
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <list> 
#include <iterator> 

using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void showlist(list<int> g);

//Execution Begins Here!
int main(int argc, char** argv) {
    cout<<"List ex 1: "<<endl;
    list <int> gqlist1, gqlist2; 
  
  
    for (int i = 0; i < 10; ++i) 
    { 
        gqlist1.push_back(i * 2); 
        gqlist2.push_front(i * 3); 
    } 
    cout << "\nList 1 (gqlist1) is : "; 
    showlist(gqlist1); 
  
    cout << "\nList 2 (gqlist2) is : "; 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.front() : " << gqlist1.front(); 
    cout << "\ngqlist1.back() : " << gqlist1.back(); 
  
    cout << "\ngqlist1.pop_front() : "; 
    gqlist1.pop_front(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.pop_back() : "; 
    gqlist2.pop_back(); 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.reverse() : "; 
    gqlist1.reverse(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.sort(): "; 
    gqlist2.sort(); 
    showlist(gqlist2); 
    //Exit the program
    return 0;
}

void showlist(list <int> g) { 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 