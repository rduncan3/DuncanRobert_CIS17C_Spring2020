/* 
 * File:   Triangle.cpp
 * Author: Robert Duncan
 * Created on March 17th, 2020, 11:12 AM
 * Purpose:  implementation for Triangle
 */

#include "Triangle.h"

Triangle::Triangle(int row){
    szRow=row;
    records=new RowAray*[szRow];
    for(int i=0;i<szRow;i++){
        records[i]=new RowAray(szRow);
    }
}

Triangle::~Triangle(){
    delete []records;
}

Triangle::getData(int row, int col){
    return records[row]->getData(col);
}