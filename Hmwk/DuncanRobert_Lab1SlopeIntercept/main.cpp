/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 17 March 2020, 11:42 AM
 * Purpose:  Slope Intercept
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <fstream>
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants
const int SIZE=37;

//Function Prototypes
float sum(float [], int);
float sum(float [],float [], int);
float slope(float [],float [], int);
float yint(float [],float [],float, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //    y = m *x     +b
    //deg_c = m *deg_f +b
    
    //Declare Variables
    float fahr[SIZE]={};
    float cel[SIZE]={};
    
    //File Variables
    ifstream deg_f; //Degree Fahr
    ifstream deg_c; //Degree Cel with error
    
    //Open Files
    deg_f.open("deg_f.dat", ios::out);
    deg_c.open("deg_c.dat", ios::out);
    
    //Copy data from files into arrays
    if(deg_f.is_open()){
        for(int i=0;i<SIZE;i++){
            deg_f>>fahr[i];
        }
    }
    if(deg_c.is_open()){
        for(int i=0;i<SIZE;i++){
            deg_c>>cel[i];
        }
    }
    
    //Input Slope/Y-int
    float m=slope(fahr,cel,SIZE);
    float b=yint(fahr,cel,m,SIZE);
    
    //Output Data
    cout<<"Slope = "<<m<<endl;
    cout<<"Y-int = "<<b<<endl;
    
    //Close Files
    deg_f.close();
    deg_c.close();
    
    //Exit the program
    return 0;
}

//Sum of x, Sum of y
float sum(float ary[], int n){
    float temp=0.0f;
    for(int i=0;i<n;i++){
        temp+=ary[i];
    }
    return temp;
}

//Sum of x*y, x^2
float sum(float ary1[], float ary2[], int n){
    float temp=0.0f;
    for(int i=0;i<n;i++){
        temp+=ary1[i]*ary2[i];
    }
    return temp;
}

float slope(float x[],float y[],int n){
    float sumOfX=sum(x,n);
    float sumOfY=sum(y,n);
    float sumXY=sum(x,y,n);
    float sumX2=sum(x,x,n);
    return (sumOfY*sumOfX-n*sumXY)/(sumOfX*sumOfX-n*sumX2);
}

float yint(float x[],float y[],float m,int n){
    float sumOfX=sum(x,n);
    float sumOfY=sum(y,n);
    return (sumOfY-m*sumOfX)/n;
}