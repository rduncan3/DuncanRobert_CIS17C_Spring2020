/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 1 October 2019, 4:37 PM
 * Purpose:  Permutations and Combinations
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <iomanip>      //setw
#include <cmath>        //pow
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes
double factorial(int);
double perm(int,int);
double permRep(int,int);
double comb(int,int);
double combRep(int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Display/Output all pertinent variables
    cout<<left<<setw(5)<<"n"<<setw(5)<<"m"<<setw(15)<<"Permutation"<<setw(27)<<
            "Permutation Replacement"<<setw(15)<<"Combination"<<setw(30)<<
            "Combination Replacement"<<endl;
    for(int n=2;n<=26;n++){
        for(int m=0;m<=n;m++){
            cout<<setw(5)<<n<<setw(5)<<m<<setw(15)<<perm(n,m)<<setw(27)<<
                    permRep(n,m)<<setw(15)<<comb(n,m)<<setw(30)<<
                    combRep(n,m)<<endl;
        }
    }
    
    //Exit the program
    return 0;
}

double factorial(int n){
    double temp=1;
    for(int i=1;i<=n;i++){
        temp*=i;
    }
    return temp;
}

double perm(int n,int m){
    double num=factorial(n);
    double den=factorial(n-m);
    return num/den;
}

double permRep(int n,int m){
    return pow(n,m);
}

double comb(int n,int m){
    double num=factorial(n);
    double den=factorial(n-m)*factorial(m);
    return num/den;;
}

double combRep(int n,int m){
    double num=factorial(n+m-1);
    double den=factorial(n-1)*factorial(m);
    return num/den;
}