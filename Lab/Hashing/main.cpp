/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 18 October 2019, 1:43 PM
 * Purpose:  Hashing
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
unsigned int mrkHash(char [],int);
void filAry(string [],string [],string [],char [],int,int);
void linSrch(string [],string [],int,int);
void binSrch(string [],string [],int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int ASIZE=80000;  //size of array of strings
    const int SSIZE=20;     //size of char array
    const int SEARCHSZ=6;   //strings to search in array of strings
    string array1[ASIZE];
    string array2[ASIZE];
    string array3[ASIZE];
    char randString[SSIZE];
    
    //Input Data/Variables
    
    //Fill the array of strings
    filAry(array1,array2,array3,randString,ASIZE,SSIZE);
    
    //Strings to search in array
    string search[SEARCHSZ]={
        array1[ASIZE-1],"blue","red",array1[ASIZE/2],array1[10],"red",
    };
    
    //Process or map the inputs to the outputs
    //Display/Output all pertinent variables

    //Linear Search
    int beg1=time(0);
    linSrch(array1,search,ASIZE,SEARCHSZ);
    int end1=time(0);
    
    
    //Binary Search
    sort(array2,array2+ASIZE);
    int beg2=time(0);
    binSrch(array2,search,ASIZE,SEARCHSZ);
    int end2=time(0);
    
    //Output results
    cout<<"Linear Search time: "<<end1-beg1<<endl;
    cout<<"Binary Search time: "<<end2-beg2<<endl;
    
    
    //Exit the program
    return 0;
}

void binSrch(string a[],string search[],int n,int nVals){
    sort(a,a+n); //Sort array
    int first=0,last=n-1,mid=0;
    bool match=false;
    for(int k=0;k<5000;k++){
        first=0,last=n-1,mid=0,match=false;
        for(int i=0;i<nVals;i++){
            while(!match&&first<=last){
                mid=(first+last)/2;
                if(a[mid]==search[i])match=true;
                else if(a[mid]>search[i])last=mid-1;
                else first=mid+1;
                //cout<<search[i]<<" : "<<a[mid]<<endl;
            }
        } 
    }
    
}

void linSrch(string a[],string search[],int n,int nVals){
    for(int i=0;i<nVals;i++){
        for(int k=0;k<5000;k++){
           for(int j=0;j<n;j++){
                //cout<<search[i]<<" : "<<a[j]<<endl;
                if(search[i]==a[j])j=n;
            } 
        }
    }
}

void filAry(string a1[],string a2[],string a3[],char strng[],int aSize,int sSize){
    for(int i=0;i<aSize;i++){
        for(int j=0;j<sSize;j++){
            strng[j]=rand()%26+65;
            if(rand()%2==1)strng[j]+=32;
        }
        strng[sSize-1]='\0';
        a1[i]=a2[i]=a3[i]=strng;
    }
}

unsigned int mrkHash(char a[],int n){
    unsigned int sum=0,prod=1;
    char c;
    for(int i=0;i<n;i++){
        if(a[i]<=91)c=a[i]-65;
        else c=a[i]-71;
        sum+=(sum+c*prod);
        prod*=52;
        prod%=9999991;
        sum%=999999991;
    }
    return sum;
}