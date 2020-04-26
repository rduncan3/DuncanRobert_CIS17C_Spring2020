/* 
 * File:   Table.cpp
 * Author: Robert Duncan
 * Created on 22 March 2020, 3:00 PM
 * Implementation for the Table
 */

#include "Table.h"

Table::Table(unsigned int row,unsigned int col){
    szRow=row;  //Set number of rows
    szCol=col;  //Set number of cols
    //Allocate memory
    columns=new RowAray*[szRow];     
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray(szCol);
    }
    setData(szRow,szCol,rand()%90+10);
}

Table::~Table(){
    delete []columns;
}

int Table::getData(int row, int col) const{
    return columns[row]->getData(col);
}

void Table::setData(int row, int col, int num){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            columns[i][j]=num;
        }
    }
}