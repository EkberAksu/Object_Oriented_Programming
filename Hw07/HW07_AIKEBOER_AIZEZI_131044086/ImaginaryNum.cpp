/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   ImaginaryNum.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#include "ImaginaryNum.h"

ImaginaryNum::ImaginaryNum(): ComplexNum(0,0){
    
}

ImaginaryNum::ImaginaryNum(double num): ComplexNum(0,num){
    
}

ImaginaryNum ImaginaryNum::operator +(const ImaginaryNum& num) const{
    ImaginaryNum temp;
    temp.setImaginary(this->getImaginary() + num.getImaginary());
    
    return temp;
}

ImaginaryNum ImaginaryNum::operator -(const ImaginaryNum& num) const{
    ImaginaryNum temp;
    temp.setImaginary(this->getImaginary() - num.getImaginary());
    
    return temp;
}

bool ImaginaryNum::operator <(const ImaginaryNum& num) const{
    return (this->getImaginary() < num.getImaginary());
}

ostream& operator <<(ostream& o ,const ImaginaryNum& num){
    o<<num.getImaginary()<<"i";
    
    return o;
}