/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Aug 27th, 2019, 12:15 pM
 * Purpose:  Triangular array
 */

//System Libraries Here
#include <iostream>  //I/O Library
#include <cstdlib>   //Random function Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int**fillAry(int *,int);       //Randomly fill a triangular array
int *fillAry(int);             //Randomly fill a 1-D column array
void prntAry(int *,int);       //Print a 1-D array
void prntAry(int **,int *,int);//Print a triangular array
void prntAry(int **,int *,int *,int);//Print a triangular array
void destroy(int **,int *,int *,int);//Deallocate memory
int *filIndx(int);             //Creates an index for an array
void markSrt(int *,int *,int); //Sorts from smallest to largest

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int *col;      //Pointer to column array
    int **trangl;  //Pointer to triangular array
    int *indx;     //Pointer to index array
    
    //Input or initialize values Here
    int colSize=10;             //Literal column array size
    col=fillAry(colSize);       //Dynamic 1-D array
    trangl=fillAry(col,colSize);//Dynamic triangular array
    indx=filIndx(colSize);      //Dynamic 1-D array

    //Output Located Here
    prntAry(col,colSize);
    prntAry(indx,colSize);
    prntAry(trangl,col,colSize);

    //Sort
    markSrt(col,indx,colSize);
    
    //Output Located Here
    prntAry(indx,colSize);
    prntAry(trangl,col,indx,colSize);
    
    //Deallocate the array
    destroy(trangl,col,indx,colSize);
    
    //Exit
    return 0;
}

void destroy(int **a,int *c,int *indx,int n){
    //Delete every row of the triangular array
    for(int i=0;i<n;i++){
        delete a[i];
    }
    //Delete the pointers
    delete []a;
    delete []c;
    delete []indx;
}

int **fillAry(int *col,int n){
    int **array=new int*[n];
    for(int i=0;i<n;i++){
        array[i]=new int[col[i]];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<col[i];j++){
            array[i][j]=rand()%9+1;//1 Digit numbers [1-9]
        }
    }
    return array;
}

void prntAry(int **array,int *col,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<col[i];j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(int **array,int *col,int *indx,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<col[indx[i]];j++){
            cout<<array[indx[i]][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%9+1;//1 Digit numbers [1-9]
    }
    return array;
}

int *filIndx(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i;
    }
    return array;
}

void markSrt(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){//Find Smallest for each list
        for(int j=i+1;j<n;j++){//Examine each element below top of list
            //Swap
            if(a[indx[i]]>a[indx[j]]){
                indx[i]=indx[i]^indx[j];
                indx[j]=indx[i]^indx[j];
                indx[i]=indx[i]^indx[j];
            }
        }
    }
}