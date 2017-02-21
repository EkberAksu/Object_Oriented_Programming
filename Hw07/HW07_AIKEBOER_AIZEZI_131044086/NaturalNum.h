/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   NaturalNum.h
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#ifndef NATURALNUM_H
#define NATURALNUM_H

#include "Integer.h"

using namespace std;

class NaturalNum: public Integer{
    public:
        NaturalNum();   //no parameter constructor, which sets 0 as default value
        NaturalNum(int num);    //one parameter constructor
        //overloaded + operator which takes one  natural number as a parameter and returns a complex number
        NaturalNum operator+(const NaturalNum& num) const;
        //overloaded - operator which takes one  natural number as a parameter and returns a complex number
        NaturalNum operator-(const NaturalNum& num) const;
        //overloaded < operator which compares tow natural numbers and returns true if the first is smaller than the second
        bool operator<(const NaturalNum& num) const;
        //overloaded friend stream insertion function
        friend ostream& operator<<(ostream& o,const NaturalNum& num);
        //setter and getters
        void setNum(const int num);
        int getNum() const;
};

#endif /* NATURALNUM_H */

