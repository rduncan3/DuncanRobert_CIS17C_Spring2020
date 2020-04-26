/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: Robert
 *
 * Created on October 8, 2019, 6:09 PM
 */

#ifndef LIST_H
#define LIST_H

#include "Link.h"

class List{
    private:
        Link *link;
    public:
        List();
        List(int);
        ~List();
        Link *fillLnk(int);
        void prntLnk();
        Link *findEnd(Link *);
        Link *pushFrt(Link *,int);
        Link *pushBck(int);
        bool findVal(int);
        int  cntVal(int);
        int  lstSize();
        void popFrt(int &);
        Link *popBck(int &);
};

#endif /* LIST_H */

