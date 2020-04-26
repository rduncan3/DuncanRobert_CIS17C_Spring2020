/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleVector.h
 * Author: rcc
 *
 * Created on September 18, 2019, 8:10 PM
 */

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   //Adding and subtracting from the Vector
   void push_front(T);
   void push_back(T);
   T    pop_front();
   T    pop_back();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//*******************************************
// Add 1 or Delete 1 front or back for SimpleVector class. *
//*******************************************

template <class T>
void SimpleVector<T>::push_front(T val){
    SimpleVector<T> temp;   //Create temp array
    temp=*this;             //Point to array
    aptr=new T[arraySize+1];//Allocate memory
    //Copy old array to new array
    for(int i=0;i<temp.size()+1;i++){
        *(aptr+i)=*(temp.aptr+(i-1));
    }
    *(aptr+0)=val; //insert value at beginning of array
    arraySize++;//Resize array
}

template <class T>
void SimpleVector<T>::push_back(T val){
    SimpleVector<T> temp;   //Create temp array
    temp=*this;             //Point to array
    aptr=new T[arraySize+1];//Allocate memory
    arraySize=temp.size();//old array size to new array size
    //Copy old array to new array
    for(int i=0;i<temp.size();i++){
    *(aptr+i)=*(temp.aptr+i);
    }
    *(aptr+arraySize)=val;//insert value at end of array
    arraySize++;//Resize array
}

template <class T>
T SimpleVector<T>::pop_front(){
    T dummy=aptr[0];
    SimpleVector<T> temp;//Create new array
    temp=*this; //Point to array
    aptr = new T [arraySize-1]; //Allocate memory
    arraySize=temp.size()-1;    //Resize array
    //Copy old array to new array
    for(int i=0;i<arraySize;i++){
        *(aptr+i)=*(temp.aptr+(i+1));
    }
    return dummy;
}

template <class T>
T SimpleVector<T>::pop_back(){
    T dummy=aptr[arraySize-1];
    arraySize--; //resize array
    return dummy;
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif