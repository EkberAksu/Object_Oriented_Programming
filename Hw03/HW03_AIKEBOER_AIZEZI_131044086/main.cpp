/* 
 * File:   main.cpp
 * Author: ekber
 *
 * Created on November 2, 2015, 6:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */
class Triangle{
public:
    Triangle();
    Triangle(double a);
    Triangle(double a,double b);
    Triangle(double a, double b, double c);
    void input();
    void output() const;
    double angleA() const;
    double angleB() const;
    double angleC() const;
    bool is_right_angle() const;
    double perimeter() const;
    double area() const;
    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setABC(double a,double b,double c);
    double getA() const;
    double getB() const;
    double getC() const;
    
private:
    bool test_ABC(double a,double b,double c) const;
    double A;
    double B;
    double C;
    
};

int cmp_triangle(const Triangle m_tri1,const Triangle m_tri2);
Triangle& sort_sides(Triangle& m_tri);

int main(int argc, char** argv) {
    Triangle tri1(3,4,5);

    return 0;
}

Triangle::Triangle(){
    setABC(1.0,1.0,1.0);
}
Triangle::Triangle(double a){
    setABC(a,a,a);
}
Triangle::Triangle(double a, double b){
    setABC(a,b,1.0);
}
Triangle::Triangle(double a, double b, double c){
    setABC(a,b,c);
}

void Triangle::setA(double a){
    A=a;
}
void Triangle::setB(double b){
    B=b;
}
void Triangle::setC(double c){
    C=c;
}
void Triangle::setABC(double a, double b, double c){
    if(test_ABC(a,b,c)){
        setA(a);
        setB(b);
        setC(c);
    }
    else{
        cout<<"oops!These sides can not make a triangle,try enter other sides.";
        exit(1);
    }
    
}

double Triangle::getA() const{
    return A;
}
double Triangle::getB() const{
    return B;
}
double Triangle::getC() const{
    return C;
}

bool Triangle::test_ABC(double a, double b, double c) const{
    return (a+b > c && a+c > b && b+c > a);
}

void Triangle::input(){
    double s_A;
    double s_B;
    double s_C;
    
    cout<<"Please enter three doubles as the sides of the triangle>\n";
    cin>>s_A>>s_B>>s_C;
    
    setABC(s_A, s_B, s_C);
 
}

void Triangle::output() const{
    
    cout<<"Length of side A of this triangle is"<<getA()<<endl
        <<"Length of side B of this triangle is"<<getB()<<endl
        <<"Length of side C of this triangle is"<<getC()<<endl;
}

double Triangle::angleA() const{
    
    double s_A = getA();
    double s_B = getB();
    double s_C = getC();
    
    return acos((pow(s_B,2)+pow(s_C,2)-pow(s_A,2))/(2*s_B*s_C));
    
}
double Triangle::angleB() const{
    
    double s_A = getA();
    double s_B = getB();
    double s_C = getC();
    
    return acos((pow(s_A,2)+pow(s_C,2)-pow(s_B,2))/(2*s_A*s_C));
    
}
double Triangle::angleC() const{
    
    double s_A = getA();
    double s_B = getB();
    double s_C = getC();
    
    return acos((pow(s_B,2)+pow(s_A,2)-pow(s_C,2))/(2*s_B*s_A));
    
}

bool Triangle::is_right_angle() const{
    
    double s_A = getA();
    double s_B = getB();
    double s_C = getC();
    
    return ((pow(s_A,2)+pow(s_B,2))==(pow(s_C,2)) || (pow(s_A,2)+pow(s_C,2))==(pow(s_B,2)) ||
            (pow(s_A,2)+pow(s_B,2))==(pow(s_C,2)) );
        
}

double Triangle::perimeter() const{
    
    double s_A = getA();
    double s_B = getB();
    double s_C = getC();
    double perimeter;
    
    perimeter = (s_A+s_B+s_C);
    
    return perimeter;
}

double Triangle::area() const{
    
    double s_A = getA();
    double s_B = getB();
    
    double AngleC = angleC();
    double Area;
    
    Area=0.5*s_A*s_B*AngleC;
    
    return Area;
}

int cmp_triangle(const Triangle m_tri1,const Triangle m_tri2){
    if(m_tri1.area()>m_tri2.area())
        return 1;
    else if(m_tri1.area()== m_tri2.area())
        return 0;
    else
        return -1;
}

Triangle& sort_sides(Triangle& m_tri){
    double a[3];
    a[0]=m_tri.getA();
    a[1]=m_tri.getB();
    a[2] =m_tri.getC();
    double temp;
    
    for(int i=0;i<3; ++i)
        for(int j=i+1;j<3;++j){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
    }
    
    m_tri.setA(a[0]);
    m_tri.setB(a[1]);
    m_tri.setC(a[2]);
    
    return m_tri;
}

