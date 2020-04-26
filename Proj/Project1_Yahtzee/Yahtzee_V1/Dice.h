 /* 
 * File:   Dice.h
 * Author: Robert Duncan
 * Created on 22 April 2020, 10:39 PM
 * Purpose:  Dice class
 */

#ifndef DICE_H
#define DICE_H

class Dice{
    private:
        int sides;                          //Number of sides
        int face;                           //Current face of die
    public:
        //Constructors
        Dice(){sides=0,face=0;}             //Default Constructor
        Dice(int n){sides=n,face=1;}        //Constructor with number of sides
        //Set Functions
        void setSide(int n){sides=n;}       //Set number of sides
        void setFace(int n){face=n;}        //Set current face
        //Get Functions
        int getSide()const{return sides;}   //Get number of sides
        int getFace()const{return face;}    //Get face of die
        //Dice Functions
        int roll(){                         //Roll die
            setFace(rand()%sides+1);
            getFace();
        }  
};

#endif /* DICE_H */

