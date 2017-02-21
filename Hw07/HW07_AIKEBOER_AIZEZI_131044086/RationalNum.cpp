/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   RationalNum.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */
#include "RationalNum.h"

RationalNum::RationalNum(): RealNum(){
    
}

RationalNum::RationalNum(double num): RealNum(num){
    if(!(num==M_E || num==M_LOG2E  || num==M_LOG10E || num==M_LN2 || num==M_LN10
        || num==M_PI || num== M_PI_2 || num== M_PI_4 || num==M_1_PI || num==M_2_PI
        || num==M_2_SQRTPI || num==M_SQRT2 || num==M_SQRT1_2)){
        
       return ;
    }
    else{
        cout<<"The input is not a rational number!"<<endl;
        exit(1);
    }
}

void RationalNum::setRational(const double num){
    if(!(num==M_E || num==M_LOG2E  || num==M_LOG10E || num==M_LN2 || num==M_LN10
        || num==M_PI || num== M_PI_2 || num== M_PI_4 || num==M_1_PI || num==M_2_PI
        || num==M_2_SQRTPI || num==M_SQRT2 || num==M_SQRT1_2)){
        
        this->setReal(num);
    }
    else{
        cout<<"The input is not a rational number!"<<endl;
        exit(1);
    }
}

double RationalNum::getRational() const{
    return this->getReal();
}

RationalNum RationalNum::operator +(const RationalNum& num) const{
    RationalNum temp;
    temp.setRational(this->getRational() + num.getRational());
    
    return temp;
}

RationalNum RationalNum::operator -(const RationalNum& num) const{
    RationalNum temp;
    temp.setRational(this->getRational() - num.getRational());
    
    return temp;
}

bool RationalNum::operator <(const RationalNum& num) const{
    return (this->getRational() < num.getRational());
}

ostream& operator << (ostream& o ,const RationalNum& num){
    o<<num.getRational();
    return o;
}