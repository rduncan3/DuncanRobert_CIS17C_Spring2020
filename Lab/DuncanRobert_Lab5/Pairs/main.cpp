/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 12 April 2019, 5:41 PM
 * Purpose:  Containers
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library

using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Pairs
    pair<int,char> pair1;
    pair1.first=33;
    pair1.second='G';
    pair<float,float> pair2(1.2,3.4);
    pair<unsigned int,int> pair3(3564,-56);
    pair<unsigned int,int>pair4(pair3);
    pair<int,char> pair5;
    pair5=make_pair(1,'a');
    cout<<"Containers:"<<endl;
    cout<<" Pairs:"<<endl;
    cout<<"     pair1 First Element: "<<pair1.first<<endl;
    cout<<"     pair1 Second Element: "<<pair1.second<<endl;
    cout<<"     pair2 First Element: "<<pair2.first<<endl;
    cout<<"     pair2 Second Element: "<<pair2.second<<endl;
    cout<<"     pair3 First Element: "<<pair3.first<<endl;
    cout<<"     pair3 Second Element: "<<pair3.second<<endl;
    cout<<"     pair4 First Element: "<<pair4.first<<endl;
    cout<<"     pair4 Second Element: "<<pair4.second<<endl;
    cout<<"     pair5 First Element: "<<pair5.first<<endl;
    cout<<"     pair5 Second Element: "<<pair5.second<<endl;
    cout<<"     pair3 == pair4: "<<(pair3==pair4)<<endl; 
    cout<<"     pair3 != pair4: "<<(pair3!=pair4)<<endl; 
    cout<<"     pair3 >= pair4: "<<(pair3>=pair4)<<endl; 
    cout<<"     pair3 <= pair4: "<<(pair3<=pair4)<<endl; 
    cout<<"     pair3 >  pair4: "<<(pair3>pair4)<<endl;
    cout<<"     pair3 <  pair4: "<<(pair3<pair4)<<endl;
    pair1.swap(pair5);
    cout<<"     Swapping pair1 and pair 5: "<<endl;
    cout<<"     pair1 new First Element: "<<pair1.first<<endl;
    cout<<"     pair1 new Second Element: "<<pair1.second<<endl;
    cout<<"     pair5 new First Element: "<<pair5.first<<endl;
    cout<<"     pair5 new Second Element: "<<pair5.second<<endl;
    //Exit the program
    return 0;
}