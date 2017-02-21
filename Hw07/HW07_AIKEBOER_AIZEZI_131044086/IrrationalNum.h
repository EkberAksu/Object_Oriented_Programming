/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   IrratinalNum.h
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#ifndef IRRATIONALNUM_H
#define IRRATIONALNUM_H

#include "RealNum.h"
#include <cmath>

using namespace std;

class IrrationalNum: public RealNum{
    public:
        IrrationalNum();    //no parameter constructor, which sets pi as a default value
        IrrationalNum(double num);  //one parameter constructor
        //overloaded + operator which takes one  irrational number as a parameter and returns a complex number
        IrrationalNum operator+(const IrrationalNum& num) const;
        //overloaded - operator which takes one  irrational number as a parameter and returns a complex number
        IrrationalNum operator-(const IrrationalNum& num) const;
        //overloaded < operator which compares tow irrational numbers and returns true if the first is smaller than the second
        bool operator<(const IrrationalNum& num) const;
        //overloaded friend stream insertion operator
        friend ostream& operator<<(ostream& o,const IrrationalNum& num);
        //setter and getters
        void setIrrational(const double num);
        double getIrrational() const;
};

#endif /* IRRATIONALNUM_H */

