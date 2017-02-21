/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   RealNum.h
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#ifndef REALNUM_H
#define REALNUM_H

#include "ComplexNum.h"

using namespace std;

class RealNum: public ComplexNum{
    public:
        RealNum();  //no parameter constructor, which sets 0.0 as default value
        RealNum(double num);    //one parameter constructor
        //overloaded + operator which takes one real number as a parameter and returns a real number
        RealNum operator+(const RealNum& num) const;
        //overloaded - operator which takes one real number as a parameter and returns a real number
        RealNum operator-(const RealNum& num) const;
        //overloaded < operator which compares tow real numbers and returns true if the first is smaller than the second
        bool operator<(const RealNum& num) const;
        //overloaded friend stream insertion operator
        friend ostream& operator<<(ostream& o,const RealNum& num);
};

#endif /* REALNUM_H */

