/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   NaturalNum.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#include "NaturalNum.h"

NaturalNum::NaturalNum(): Integer(){
    
}

NaturalNum::NaturalNum(int num): Integer(num){
    if(num >=0) return;
    else{
        cout<<"The input is not a natural number!"<<endl;
        exit(1);
    }
}

void NaturalNum::setNum(const int num){
    if(num >=0){
        this->setInteger(num);
    }
    else{
        cout<<"The input is not a natural number!"<<endl;
        exit(1);
    }
}

int NaturalNum::getNum() const{
    return this->getInteger();
}

NaturalNum NaturalNum::operator +(const NaturalNum& num) const{
    NaturalNum temp;
    temp.setNum(this->getNum() + num.getNum());
    return temp;
}

NaturalNum NaturalNum::operator -(const NaturalNum& num) const{
    NaturalNum temp;
    temp.setNum(this->getNum() - num.getNum());
    return temp;
}

bool NaturalNum::operator <(const NaturalNum& num) const{
    return (this->getNum() < num.getNum());
}

ostream& operator <<(ostream& o,const NaturalNum& num){
    o<<num.getNum();
    return o;
}