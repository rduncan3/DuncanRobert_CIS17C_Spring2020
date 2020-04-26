/* 
 * Author: Robert Duncan
 * Created on March 25th, 2020, 10:46 AM
 * Purpose:  Row Template
 */

#ifndef ROWARAY_H
#define ROWARAY_H

template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

template<class T>
RowAray<T>::RowAray(int col){
    size=col;            //Set num of col
    rowData=new T[col];  //Allocate Memory
    for(int i=0;i<col;i++){
        setData(i,rand()%90+10);
    }
}

template<class T>
void RowAray<T>::setData(int col, T num){
    rowData[col]=num;
}

template<class T>
RowAray<T>::~RowAray(){
    delete []rowData;
}

#endif /* ROWARAY_H */