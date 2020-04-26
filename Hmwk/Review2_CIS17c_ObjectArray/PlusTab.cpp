/* 
 * Author: Robert Duncan
 * Created on 22 March 2019, 3:16 PM
 * Implementation for the Table addition operator
 */

#include "PlusTab.h"

PlusTab PlusTab::operator +(const PlusTab &oldTabl){
    PlusTab newTabl(szRow,szCol);
    for(int i=0;i<szRow;i++) {
        for(int j=0;j<szCol;j++){
            (newTabl.columns[i])->setData(j,getData(i,j)+oldTabl.getData(i,j));
        }
    }
    return newTabl;
}