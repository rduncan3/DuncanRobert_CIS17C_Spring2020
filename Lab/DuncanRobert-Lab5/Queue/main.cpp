/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 11 October 2019, 12:36 PM
 * Purpose:  Queue
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <queue> 

using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void showq(queue<int>);

//Execution Begins Here!
int main(int argc, char** argv) {
    queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(20); 
    gquiz.push(30); 
  
    cout << "The queue gquiz is : "; 
    showq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.front() : " << gquiz.front(); 
    cout << "\ngquiz.back() : " << gquiz.back(); 
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showq(gquiz); 
    //Exit the program
    return 0;
}

void showq(queue <int> gq) 
{ 
    queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 