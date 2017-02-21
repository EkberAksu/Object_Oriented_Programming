/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   IrrationalNum.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#include "IrrationalNum.h"

IrrationalNum::IrrationalNum(double num): RealNum(num){
    if(num==M_E || num==M_LOG2E  || num==M_LOG10E || num==M_LN2 || num==M_LN10
        || num==M_PI || num== M_PI_2 || num== M_PI_4 || num==M_1_PI || num==M_2_PI
        || num==M_2_SQRTPI || num==M_SQRT2 || num==M_SQRT1_2){
        
        return;
    }
    else{
        cout<<"The input is not a irrational number!"<<endl;
        exit(1);
    }
}

void IrrationalNum::setIrrational(const double num){
   
    this->setReal(num);
}

double IrrationalNum::getIrrational() const{
    return this->getReal();
}

IrrationalNum IrrationalNum::operator+(const IrrationalNum& num) const{
    IrrationalNum temp(M_PI);
    temp.setIrrational(this->getIrrational() + num.getIrrational());
    
    return temp;
}

IrrationalNum IrrationalNum::operator-(const IrrationalNum& num) const{
    IrrationalNum temp(M_PI);
    temp.setIrrational(this->getIrrational() - num.getIrrational());
    
    return temp;
}

bool IrrationalNum::operator <(const IrrationalNum& num) const{
    return (this->getIrrational() < num.getIrrational());
}

ostream& operator << (ostream& o ,const IrrationalNum& num){
    o<<num.getIrrational()<<"...";
    return o;
}
