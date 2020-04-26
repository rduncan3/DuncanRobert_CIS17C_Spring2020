/* 
 * File:   RowAray.cpp
 * Author: Robert Duncan
 * Created on 22 March 2020, 2:47 PM
 * Implementation for the RowAray
 */

#include "RowAray.h"

RowAray::RowAray(unsigned int col){
    size=col;               //Set num of col
    rowData=new int[size];  //Allocate Memory
    //Initialize array
    setData(size,rand()%90+10); //rand 10-99]
}

RowAray::~RowAray(){
    delete []rowData;
}

void RowAray::setData(int col, int num){
    for(int i=0;i<col;i++){
        rowData[i]=num;
    }
}