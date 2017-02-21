/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   RationalNum.h
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include "RealNum.h"
#include <cmath>

using namespace std;

class RationalNum: public RealNum{
    public:
        RationalNum();  //no parameter constructor, which sets 0.0 as a default vale
        RationalNum(double num);    //one parameter constructor
        //overloaded + operator which takes one  rational number as a parameter and returns a complex number
        RationalNum operator+(const RationalNum& num) const;
        //overloaded - operator which takes one  rational number as a parameter and returns a complex number
        RationalNum operator-(const RationalNum& num) const;
        //overloaded < operator which compares tow rational numbers and returns true if the first is smaller than the second
        bool operator<(const RationalNum& num) const;
        //overloaded friend stream insertion operator
        friend ostream& operator<<(ostream& o,const RationalNum& num);
        //setter and getters
        void setRational(const double num);
        double getRational() const;
};


#endif /* RATIONAL_H */

