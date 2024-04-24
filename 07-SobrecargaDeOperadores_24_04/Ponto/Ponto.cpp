#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

class Ponto {
  private:
    double x,y;
  public:
    Ponto(double x=0, double y=0);
    ~Ponto();
    double obtemX() const;
    double obtemY() const;
    void defineX(double x);
    void defineY(double y);
    double distancia(const Ponto &p) const;
    Ponto pontoMedio(const Ponto &p) const;
    string str() const;
    Ponto operator+(const Ponto &p) const;
    Ponto operator-(const Ponto &p) const;
    Ponto operator-() const;
    bool operator==(const Ponto &p) const;
    bool operator!=(const Ponto &p) const;
    void operator=(const Ponto &p);
    friend ostream& operator<<(ostream& out,const Ponto& p);
    friend istream& operator>>(istream& in,Ponto& p);
};

Ponto::Ponto(double x, double y) {
  this->x = x;
  this->y = y;
#ifdef DEBUG
  cout << "+ Ponto " << str() << " criado..." << endl;
#endif
}

Ponto::~Ponto() {
#ifdef DEBUG
  cout << "- Ponto " << str() << " destruído..." << endl;
#endif
}

double Ponto::obtemX() const {
  return x;
}

double Ponto::obtemY() const {
  return y;
}

void Ponto::defineX(double x) {
  this->x = x;
}

void Ponto::defineY(double y) {
  this->y = y;
}

double Ponto::distancia (const Ponto &p) const {
  return sqrt(pow(x-p.obtemX(),2)+pow(y-p.obtemY(),2));
}

Ponto Ponto::pontoMedio (const Ponto &p) const {
  return Ponto( (x+p.obtemX())/2.0, (y+p.obtemY())/2.0 );
}

string Ponto::str() const {
  stringstream ss;
  ss << "(" << x << "," << y << ")";
  return ss.str();
}

Ponto Ponto::operator+(const Ponto &p) const {
  return Ponto(x+p.obtemX(), y+p.obtemY());
}

Ponto Ponto::operator-(const Ponto &p) const {
  return Ponto(x-p.obtemX(), y-p.obtemY());
}

Ponto Ponto::operator-() const {
  return Ponto(-x, -y);
}

bool Ponto::operator==(const Ponto &p) const {
  return p.obtemX() == x && p.obtemY() == y;
}

bool Ponto::operator!=(const Ponto &p) const {
  return p.obtemX() != x || p.obtemY() != y;
}

void Ponto::operator=(const Ponto &p) {
  x = p.obtemX();
  y = p.obtemY();
}

ostream& operator<<(ostream& out,const Ponto& p) {
  out << p.str();
  return out;
}

istream& operator>>(istream& in,Ponto& p) {
  cout << "X: ";
  in >> p.x;
  cout << "Y: ";
  in >> p.y;
  return in;
}

int main() {
  Ponto a(4,0), b(0,3);

  cout << "a.str()=" << a.str() << endl;
  cout << "b.str()=" << b.str() << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  cout << "a.distancia(b)=" << a.distancia(b) << endl;
  cout << "a.pontoMedio(b)=" << a.pontoMedio(b) << endl;
  a.defineX(a.obtemX()+1);
  a.defineY(a.obtemY()+1);
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << "a.obtemX()=" << a.obtemX() << " a.obtemY()=" << a.obtemY() << endl;
  cout << "a.distancia(b)=" << a.distancia(b) << endl;
  cout << "a.pontoMedio(b)=" << a.pontoMedio(b) << endl;
  cout << endl;

  Ponto c(5,1), d(4,0), e;

  e = c+d;
  cout << "c=" << c << endl;
  cout << "d=" << d << endl;
  cout << "e=c+d=" << e << endl;
  cout << endl;

  e = c-d;
  cout << "c=" << c << endl;
  cout << "d=" << d << endl;
  cout << "e=c-d=" << e << endl;
  cout << endl;

  e = -c;
  cout << "c=" << c << endl;
  cout << "e=-c=" << e << endl;
  cout << endl;

  cout << "a=" << a << endl;
  cout << "c=" << c << endl;
  cout << "d=" << d << endl;
  if ( a == c )
     cout << "a == c" << endl;
  else
     cout << "a != c" << endl;
  if ( a == d )
     cout << "a == d" << endl;
  else
     cout << "a != d" << endl;
  if ( a != c )
     cout << "a != c" << endl;
  else
     cout << "a == c" << endl;
  if ( a != d )
     cout << "a != d" << endl;
  else
     cout << "a == d" << endl;
  cout << endl;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  a=b;
  cout << "a=b;" << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
  cout << endl;

  cout << "e=" << e << endl;
  cout << "e:" << endl;
  cin >> e;
  cout << "e=" << e << endl;

  return 0;
}