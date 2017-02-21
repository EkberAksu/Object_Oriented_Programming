/* 
 * HW07_AIKEBOER_AIZEZI_131044086
 * File:   main.cpp
 * Author: Akbar Aziz
 *
 * Created on December 15, 2015, 5:49 PM
 */

#include <iostream>
#include <cmath>
#include "NaturalNum.h"
#include "IrrationalNum.h"
#include "ImaginaryNum.h"

using namespace std;

/*
 * This is a main function to test all the number classes 
 * that are defined in this application
 */
int main(int argc, char** argv) {
    
    //test for complex number
    ComplexNum num1(3.5,2.5);
    ComplexNum num2(1.5);
    
    num2 = num1+num2;
    cout<<"This is a complex number :"<<num2<<endl;
    
    if(num1 < num2){
        num2= num2-num1;
        cout<<"This is a complex number :"<<num2<<endl;
    }
    cout<<"----------------------------"<<endl;
    //test for real number
    RealNum num3(2.5);
    RealNum num4(0.5);
    
    num4 = num3 + num4;
    cout<<"This is a real number :"<<num4<<endl;
    
    if(num3 < num4){
        num4 = num4 - num3;
        cout<<"This is a real number :"<<num4<<endl;
    }
    cout<<"----------------------------"<<endl;
    //test for imaginary number
    ImaginaryNum num5(4);
    ImaginaryNum num6(1.75);
    
    num6 = num5+ num6;
    cout<<"This is a imaginary number :"<<num6<<endl;
    
    if(num5 < num6){
        num6 = num6 - num5;
        cout<<"This is a imaginary number :"<<num6<<endl;
    }
    cout<<"----------------------------"<<endl;
    //test for irrational number
    IrrationalNum num7(M_PI);
    IrrationalNum num8(M_E);
    
    num8 = num7 + num8;
    cout<<"This is a irrational number :"<<num8<<endl;
    
    if(num7 < num8){
        num8 = num8 - num7;
        cout<<"This is a irrational number :"<<num8<<endl;
    }
    cout<<"----------------------------"<<endl;
    //test for rational number
    RationalNum num9(5.0/4);
    RationalNum num10(0.8);
    
    num10 = num9 + num10;
    cout<<"This is a rational number :"<<num10<<endl;
    
    if(num9 < num10){
        num10 = num10 - num9;
        cout<<"This is a rational number :"<<num10<<endl;
    }
    cout<<"----------------------------"<<endl;
    //test for  integer
    Integer num11(-19);
    Integer num12(7);
    
    num12 = num12 + num11;
    cout<<"This is a integer :"<<num12<<endl;
    
    if(num11 < num12){
        num12 = num12 - num11;
        cout<<"This is a integer :"<<num12<<endl;
    }
    cout<<"----------------------------"<<endl;
    //test for natural number
    NaturalNum num13(8);
    NaturalNum num14(1);
    
    num14 = num13 + num14;
    cout<<"This is a natural :"<<num14<<endl;
    
    if(num13 < num14){
        num14 = num14 - num13;
        cout<<"This is a natural :"<<num14<<endl;
    }
    
    return 0;
}

