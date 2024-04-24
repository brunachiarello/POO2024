// Complex.hpp (Roland Teodorowitsch; 12 abr. 2022)

#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

using namespace std;

class Complex {
  private:
    double r;
    double i;
  public:
    Complex(double r=0.0,double i=0.0);
    ~Complex();
    double getReal() const;
    double getImaginary() const;
    void setReal(double r);
    void setImaginary(double r);
    Complex sum(const Complex &n) const;
    string str() const;
    Complex operator*  (const Complex &n) const;
    Complex operator+  (const Complex &n) const;
    Complex operator-  (const Complex &n) const;
    Complex operator-  () const;
    bool operator== (const Complex &n) const;
    bool operator!= (const Complex &n)const;
    void operator=  (const Complex &n);
    friend ostream& operator<<(ostream& out, const Complex& n);
    friend istream& operator>>(istream& in, Complex& n);
};

#endif
