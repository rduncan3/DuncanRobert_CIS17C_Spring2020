/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "iostream"
#include "List.h"
using namespace std;

List::List(){
    link=0;
}

List::List(int n){
    link=fillLnk(n);
}

Link *List::fillLnk(int n){
    Link *front=0;
    int cnt=n;
    do{
        front=pushFrt(front,cnt--);
    }while(cnt);
    return front;
}

Link *List::popBck(int &val){
    if(!link)return 0;
    Link *front=link,*back;
    while(front->ptr){
        back=front;
        front=front->ptr;
    }
    val=front->data;
    delete front;
    back->ptr=0;
    return link;
}

void List::popFrt(int &val){
    val=link->data;
    Link *front=new Link; 
    front=link;
    link=link->ptr;
    delete link;
}

int List::lstSize(){
    Link *front=link;
    int cnt=0;
    while(front){
        cnt++;
        front=front->ptr;
    }
    return cnt;
}

int List::cntVal(int val){
    Link *front=link;
    int cnt=0;
    while(front){
        if(front->data==val)cnt++;
        front=front->ptr;
    }
    return cnt;
}

bool List::findVal(int val){
    Link *front=link;
    while(front){
        if(front->data==val)return true;
        front=front->ptr;
    }
    return false;
}

Link *List::pushBck(int val){
    Link *back=new Link;
    back->data=val;
    back->ptr=0;
    Link *end=findEnd(link);
    end->ptr=back;
    return link;
}

Link *List::pushFrt(Link *list,int val){
    Link *front=new Link;
    front->data=val;
    front->ptr=list;
    return front;
}

Link *List::findEnd(Link * linkk){
    Link *front=linkk,*back;
    while(front){
        back=front;
        front=front->ptr;
    }
    return back;
}
List::~List(){
    
}

void List::prntLnk(){
    Link *front=link;
    cout<<endl;
    while(front){
        cout<<front->data<<endl;
        front=front->ptr;
    }
    cout<<endl;
}