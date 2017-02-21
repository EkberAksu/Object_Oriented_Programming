/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   Integer.h
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#ifndef INTEGER_H
#define INTEGER_H

#include "RationalNum.h"

using namespace std;

class Integer: public RationalNum{
    public:
        Integer();  //no parameter constructor, which sets 0 as default value
        Integer(int num);   //no parameter constructor
        //overloaded + operator which takes one  integer as a parameter and returns a complex number
        Integer operator+(const Integer& num) const;
        //overloaded - operator which takes one integer as a parameter and returns a complex number
        Integer operator-(const Integer& num) const;
        //overloaded < operator which compares tow integers and returns true if the first is smaller than the second
        bool operator<(const Integer& num) const;
        //overloaded friend stream insertion operator
        friend ostream& operator<<(ostream& o,const Integer& num);
        //setters and getters
        void setInteger(const int num);
        int getInteger() const;
};

#endif /* INTEGER_H */

