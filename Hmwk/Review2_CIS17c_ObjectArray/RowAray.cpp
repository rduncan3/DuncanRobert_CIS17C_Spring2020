/* 
 * File:   RowAray.cpp
 * Author: Robert Duncan
 * Created on 22 March 2020, 2:47 PM
 * Implementation for the RowAray
 */

#include "RowAray.h"

RowAray::RowAray(unsigned int col){
    size=col;
    rowData=new int[col];
}

RowAray::~RowAray(){
    delete []rowData;
}

void RowAray::setData(int col, int num){
    rowData[col]=num;
}