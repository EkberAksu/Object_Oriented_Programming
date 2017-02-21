/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   RealNum.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#include "RealNum.h"

using namespace std;

RealNum::RealNum(){
    ComplexNum(0);
}

RealNum::RealNum(double num): ComplexNum(num){
}

RealNum RealNum::operator +(const RealNum& num) const{
    RealNum temp;
    temp.setReal(this->getReal() + num.getReal());
    
    return temp;
}

RealNum RealNum::operator -(const RealNum& num) const{
    RealNum temp;
    temp.setReal(this->getReal() - num.getReal());
    
    return temp;
}

bool RealNum::operator <(const RealNum& num) const{
    return (this->getReal() < num.getReal());
}

ostream& operator <<(ostream& o, const RealNum& num){
    o<<num.getReal();
    return o;
}