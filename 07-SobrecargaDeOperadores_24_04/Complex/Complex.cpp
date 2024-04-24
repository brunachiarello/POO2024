#include <sstream>
#include "Complex.hpp"

Complex::Complex(double r,double i) {
  this->r = r;
  this->i = i;
#ifdef DEBUG
  cout << "+ Complex " << str() << " created..." << endl;
#endif
}

Complex::~Complex() {
#ifdef DEBUG
  cout << "- Complex " << str() << " destructed..." << endl;
#endif
}

double Complex::getReal() const {
  return r;
}

double Complex::getImaginary() const {
  return i;
}

void Complex::setReal(double r) {
  this->r = r;
}

void Complex::setImaginary(double i) {
  this->i = i;
}

Complex Complex::sum(const Complex &n) const {
  return Complex (r + n.getReal(), i + n.getImaginary());
}

string Complex::str() const {
  stringstream ss_ni;
  if (i > 0)
     ss_ni << r << "+" << i << "i";
  else if (i==0)
     ss_ni << r;
  else
     ss_ni << r << i << "i";
  return ss_ni.str();
}

Complex Complex::operator*(const Complex &n) const {
  Complex res;
  res.setReal(r*n.getReal() - i*n.getImaginary());
  res.setImaginary(r*n.getImaginary() + i*n.getReal());
  return res;
}

Complex Complex::operator+(const Complex &n) const {
  Complex res;
  res.setReal(r + n.getReal());
  res.setImaginary(i + n.getImaginary());
  return res;
}

Complex Complex::operator-(const Complex &n) const {
  Complex res;
  res.setReal(r-n.getReal());
  res.setImaginary(i-n.getImaginary());
  return res;
}

Complex Complex::operator-() const {
  Complex res;
  res.setReal(-r);
  res.setImaginary(-i);
  return res;
}

bool Complex::operator== (const Complex &n) const {
  return n.getReal() == r && n.getImaginary() == i;
}

bool Complex::operator!= (const Complex &n) const {
  return n.getReal() != r || n.getImaginary() != i;
}

void Complex::operator= (const Complex &n) {
  r = n.getReal();
  i = n.getImaginary();
}

ostream& operator<<(ostream& out, const Complex& n) {
  out << n.str();
  return out;
}

istream& operator>>(istream& in, Complex& n) {
  cout << "Real: ";
  in >> n.r;
  cout << "Imaginary: ";
  in >> n.i;
  return in;
}

