/* 
 * File:   Table.cpp
 * Author: Robert Duncan
 * Created on March 16th, 2020, 4:49 PM
 * Purpose:  implementation for Table
 */

#include "Table.h"

Table::Table(int row, int col){
    szRow=row;  //Set number of rows
    szCol=col;  //Set number of cols
    //Allocate memory
    records=new RowAray*[szRow];     
    for(int i=0;i<szRow;i++){
        records[i]=new RowAray(szCol);
    }
}

Table::~Table(){
    delete []records;
}

int Table::getData(int row, int col){
    return records[row]->getData(col);
}