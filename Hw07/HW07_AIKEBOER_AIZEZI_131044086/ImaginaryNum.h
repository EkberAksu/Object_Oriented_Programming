/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   ImaginaryNum.h
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#ifndef IMAGINARYNUM_H
#define IMAGINARYNUM_H

#include "ComplexNum.h"

using namespace std;

class ImaginaryNum: public ComplexNum{
    public:
        ImaginaryNum();  //no parameter constructor,which sets 0i as a default value
        ImaginaryNum(double num);   //one parameter constructor
        //overloaded + operator which takes one imaginary number as a parameter and returns a complex number
        ImaginaryNum operator+(const ImaginaryNum& num) const;
        //overloaded - operator which takes one imaginary number as a parameter and returns a complex number
        ImaginaryNum operator-(const ImaginaryNum& num) const;
        //overloaded < operator which compares tow imaginary numbers and returns true if the first is smaller than the second
        bool operator<(const ImaginaryNum& num) const;
        //overloaded friend stream insertion operator
        friend ostream& operator<<(ostream& o,const ImaginaryNum& num);
};

#endif /* IMAGINARYNUM_H */

