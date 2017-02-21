/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   ComplexNum.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#include "ComplexNum.h"

ComplexNum::ComplexNum(double num1, double num2){
    setReal(num1);
    setImaginary(num2);
}

ComplexNum::ComplexNum(double num){
    setReal(num);
    setImaginary(0);
}

ComplexNum::ComplexNum(){
    setReal(0.0);
    setImaginary(0.0);
}

void ComplexNum::setReal(const double num){
    real=num;
}

void ComplexNum::setImaginary(const double num){
    imaginary=num;
}

double ComplexNum::getReal() const{
    return real;
}

double ComplexNum::getImaginary() const{
    return imaginary;
}

ComplexNum ComplexNum::operator +(const ComplexNum& num) const{
    ComplexNum temp;
    temp.setReal(this->real + num.getReal());
    temp.setImaginary(this->imaginary + num.getImaginary());
    
    return temp;
}

ComplexNum ComplexNum::operator -(const ComplexNum& num) const{
    ComplexNum temp;
    temp.setReal(this->real - num.getReal());
    temp.setImaginary(this->imaginary - num.getImaginary());
    
    return temp;
}

bool ComplexNum::operator <(const ComplexNum& num) const{
    if(this->real < num.getReal()) return true;
    else if( this->imaginary < num.getImaginary()) return true;
    return false;
}

ostream& operator <<(ostream& o,const ComplexNum& num){
    if(num.getImaginary()==0)
        o<<num.getReal();
    else
        o<<num.getReal()<<"+"<<num.getImaginary()<<"i";
    return o;
}