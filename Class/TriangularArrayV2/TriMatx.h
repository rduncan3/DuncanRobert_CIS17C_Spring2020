/* 
 * File:   main.cpp
 * Author: Robert Duncan
 * Created on 5 September 2019
 * Purpose:  Triangular array in Order
 */

#ifndef TRIMATX_H
#define TRIMATX_H

struct TriMatx{

     int size;           //Represents the number of rows

     int *col;          //Represents the column array, i.e. number of columns for each row

     int *indx;      //Represents the index matrix which you can sort to use for display

     int **data;    //Represents the data contents of the Triangular matrix

}

#endif /* TRIMATX_H */

