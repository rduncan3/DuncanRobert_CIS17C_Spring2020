/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   Sept 24th, 2019
 * Purpose:Exploration of a Linked List
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Link.h"

//Global Constants

//Function Prototypes
Link *fillLnk(int);
void prntLnk(Link *);
void destroy(Link *);
Link *findEnd(Link *);
Link *pushFrt(Link *,int);
Link *pushBck(Link *,int);
bool findVal(Link *,int);
int  cntVal(Link *,int);
int  lstSize(Link *);
Link *popFrt(Link *,int &);
Link *popBck(Link *,int &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    Link *list;
    
    //Initialize Variables
    list=fillLnk(5);
    prntLnk(list);
    
    //Process inputs to outputs/map
    
    //Display the results
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    int val;
    cout<<"Testing popping a value from the front"<<endl;
    list=popFrt(list,val);
    cout<<"Value from the front = "<<val<<endl;
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    cout<<"Testing popping a value from the back"<<endl;
    list=popBck(list,val);
    cout<<"Value from the Back = "<<val<<endl;
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    cout<<"Testing pushing a value from the back"<<endl;
    list=pushBck(list,7);
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    cout<<"Testing pushing a value from the front"<<endl;
    list=pushFrt(list,24);
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    //Clean up 
    destroy(list);
    
    //Exit stage right
    return 0;
}

Link *popBck(Link *list,int &val){
    if(!list)return 0;
    Link *front=list,*back;
    while(front->ptr){
        back=front;
        front=front->ptr;
    }
    val=front->data;
    delete front;
    back->ptr=0;
    return list;
}

Link *popFrt(Link *list,int &val){
    if(!list)return 0;
    val=list->data;
    Link *front=list->ptr;
    delete list;
    return front;
}

int lstSize(Link *list){
    Link *front=list;
    int cnt=0;
    while(front){
        cnt++;
        front=front->ptr;
    }
    return cnt;
}

int cntVal(Link *list,int val){
    Link *front=list;
    int cnt=0;
    while(front){
        if(front->data==val)cnt++;
        front=front->ptr;
    }
    return cnt;
}

bool findVal(Link *list,int val){
    Link *front=list;
    while(front){
        if(front->data==val)return true;
        front=front->ptr;
    }
    return false;
}

Link *pushBck(Link *list,int val){
    Link *back=new Link;
    back->data=val;
    back->ptr=0;
    Link *end=findEnd(list);
    end->ptr=back;
    return list;
}

Link *pushFrt(Link *list,int val){
    Link *front=new Link;
    front->data=val;
    front->ptr=list;
    return front;
}

Link *findEnd(Link *list){
    Link *front=list,*back;
    while(front){
        back=front;
        front=front->ptr;
    }
    return back;
}

void destroy(Link *list){
    Link *front=list;
    while(front){
        Link *temp=front;
        front=front->ptr;
        delete temp;
    }
    list->ptr=0;
}

void prntLnk(Link *list){
    Link *front=list;
    cout<<endl;
    while(front){
        cout<<front->data<<endl;
        front=front->ptr;
    }
    cout<<endl;
}

Link *fillLnk(int n){
    Link *front=0;
    int cnt=n;
    do{
        front=pushFrt(front,cnt--);
    }while(cnt);
    return front;
}