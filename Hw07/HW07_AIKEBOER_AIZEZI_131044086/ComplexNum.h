
/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   ComplexNum.h
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H

#include <iostream>
#include <cmath>

using namespace std;

class ComplexNum{
    public:
        ComplexNum(double num1, double num2);  //two parameter constructor
        ComplexNum(double num);         //single-parameter constructor, which sets real part to the num, imaginary to 0
        ComplexNum();       //no-parameter constructor,, which sets (0.0,0.0) as default values
        //overloaded + operator which takes one complex number as a parameter and returns a complex number
        ComplexNum operator+(const ComplexNum& num) const; 
        //overloaded - operator which takes one complex number as a parameter and returns a complex number
        ComplexNum operator-(const ComplexNum& num) const;  
        //overloaded < operator which compares tow complex numbers and returns true if the first is smaller than the second
        bool operator<(const ComplexNum& num) const;
        //overloaded friend stream insertion operator
        friend ostream& operator<<(ostream& o,const ComplexNum& num);
        //setters and getters
        void setReal(const double num );
        void setImaginary(const double num);
        double getReal() const;
        double getImaginary() const;
    private:
        double real;
        double imaginary;
};

#endif /* COMPLEXNUM_H */

