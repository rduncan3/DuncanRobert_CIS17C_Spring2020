/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 12 April 2019, 5:41 PM
 * Purpose:  Stacks
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <stack>

using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
void showstack(stack<int>);

//Execution Begins Here!
int main(int argc, char** argv) {
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
    //Exit the program
    return 0;
}

void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 