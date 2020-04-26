/* 
 * File:   RowAray.cpp
 * Author: Robert Duncan
 * Created on March 16th, 2020, 4:23 PM
 * Purpose:  implementation for RowAray
 */

#include "RowAray.h"

RowAray::RowAray(int col){
    size=col;               //Set num of col
    rowData=new int[size];  //Allocate Memory
    //Initialize array
    for(int i=0;i<size;i++){
        rowData[i]=rand()%90+10;//[10-99]
    }
}

RowAray::~RowAray(){
    delete []rowData;
}
