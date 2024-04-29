#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;    

class Circulo {
private:
    double x, y, raio;
public:
    Circulo(double px=0.0, double py=0.0, double r=0.0);
    ~Circulo();
    double obtemX() const;
    double obtemY() const;
    double obtemRaio() const;
    void defineX(double px);
    void defineY(double py);
    void defineRaio(double r);
    string str() const;
    Circulo operator+(const Circulo &c) const;
    double operator+() const;
    friend ostream &operator<<(ostream &out, const Circulo &c);
    friend istream &operator>>(istream &in, Circulo &c);
};

Circulo :: Circulo(double px, double py, double r){
    x = px;
    y = py;
    raio = r;
}

Circulo :: ~Circulo(){

}

double Circulo :: obtemX() const{
    return x;
}

double Circulo :: obtemY() const{
    return y;
}

double Circulo :: obtemRaio() const{
    return raio;
}

void Circulo :: defineX(double px){
    x = px;
}

void Circulo :: defineY(double py){
    y = py;
}

void Circulo :: defineRaio(double r){
    raio = r;
}

string Circulo :: str() const{  
    stringstream ss;
    ss << "c=(" << fixed << setprecision(4) << x 
       << "," << fixed << setprecision(4) << y 
       << ") r=" << fixed << setprecision(4) << raio;
    return ss.str();
}

/* operador aritmetico binario + (retornando um novo cırculo localizado no ponto medio dos dois cırculos indicados na soma, 
com raio equivalente ao de um cırculo cuja area e igual a soma das areas dos dois cırculos indicados na soma) */
Circulo Circulo :: operator+(const Circulo &c) const{
    double area = (M_PI * raio * raio) + (M_PI * c.obtemRaio() * c.obtemRaio());
    double rr = sqrt(area/M_PI);
    return Circulo((x + c.obtemX()) / 2, (y + c.obtemY()) / 2, rr);
}

double Circulo :: operator+() const{
    return M_PI * raio * raio;
}

ostream &operator<<(ostream &out, const Circulo &c){
    out << c.str();
    return out;
}

istream &operator>>(istream &in, Circulo &c){
    in >> c.x >> c.y >> c.raio;
    return in;
}

int main() {
    Circulo c1, c2;
    cin >> c1;
    cin >> c2;
    cout << c1 << " a=" << fixed << setprecision(4) << +c1 << endl;
    cout << c2 << " a=" << fixed << setprecision(4) << +c2 << endl;
    Circulo c3 = c1 + c2;
    cout << c3 << " a=" << fixed << setprecision(4) << +c3 << endl;
    return 0;
}
