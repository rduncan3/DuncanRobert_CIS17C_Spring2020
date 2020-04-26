/* 
 * Author: Robert Duncan
 * Created on March 25th, 2020, 10:46 AM
 * Purpose:  Table Template
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h"

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::Table(unsigned int row,unsigned int col){
    szRow=row;  //Set number of rows
    szCol=col;  //Set number of cols
    //Allocate memory
    columns=new RowAray<T>*[row];     
    for(int i=0;i<row;i++){
        columns[i]=new RowAray<T>(col);
    }
    //Set Data
    for(int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            columns[i]->setData(j,(rand()%90+10));
        }
    }
}

template<class T>
Table<T>::Table(const Table<T> &oldTabl){
    szRow=oldTabl.getSzRow();
    szCol=oldTabl.getSzCol();
    //Allocate Memory
    columns=new RowAray<T>*[oldTabl.getSzRow()];     
    for(int i=0;i<oldTabl.getSzRow();i++){
        columns[i]=new RowAray<T>(oldTabl.getSzCol());
    }
    //Copy Data
    for(int i=0;i<oldTabl.getSzRow();i++) {
        for (int j=0;j<oldTabl.getSzCol();j++) {
            columns[i]->getData(oldTabl.getData(i,j));
        }
    }
}

template<class T>
Table<T>::~Table(){
    for(int i=0;i<szRow;i++){
        delete columns[i];
    }
    delete []columns;
}

template<class T>
T Table<T>::getData(int row, int col) const{
    return columns[row]->getData(col);
}

template<class T>
void Table<T>::setData(int row, int col, T num){
    columns[row]->setData(col,num);
}

template<class T>
Table<T> Table<T>::operator +(const Table<T> &oldTabl){
    Table<T> newTabl(szRow,szCol);
    for(int i=0;i<szRow;i++) {
        for(int j=0;j<szCol;j++){
            (newTabl.columns[i])->setData(j,getData(i,j)+oldTabl.getData(i,j));
        }
    }
    return newTabl;
}

#endif /* TABLE_H */

