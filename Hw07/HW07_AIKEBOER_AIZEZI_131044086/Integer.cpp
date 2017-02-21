/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   Integer.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#include "Integer.h"

Integer::Integer(): RationalNum(){
    
}

Integer::Integer(int num): RationalNum(num){
    
}

void Integer::setInteger(const int num){
    this->setRational(num);
}

int Integer::getInteger() const{
    return (int)this->getRational();
}

Integer Integer::operator +(const Integer& num) const{
    Integer temp;
    temp.setInteger(this->getInteger() + num.getInteger());
    
    return temp;
}

Integer Integer::operator -(const Integer& num) const{
    Integer temp;
    temp.setInteger(this->getInteger() - num.getInteger());
    
    return temp;
}

bool Integer::operator <(const Integer& num) const{
    return (this->getInteger() < num.getInteger());
}

ostream& operator <<(ostream& o,const Integer& num){
    o<<num.getInteger();
    return o;
}