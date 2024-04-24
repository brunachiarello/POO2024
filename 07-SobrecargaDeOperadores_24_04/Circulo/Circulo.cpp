#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Circulo {
private:
    double px, py, raio;

    double _area(){
        return M_PI * raio * raio;
    }

    double _circunferencia(){
        return 2.0 * M_PI * raio;
    }

public:
    Circulo(){
        px = py = 0.0;
        raio = 1.0;
    }

    Circulo(double r){
        px = py = 0.0;
        raio = r;
    }

    Circulo(double x, double y){
        px = x;
        py = y;
        raio = 1.0;
    }

    Circulo(double x, double y, double r){
        px = x;
        py = y;
        raio = r;
    }

    double obtemX() const { 
        return px; 
    }   
    
    void defineX(double x){ 
        px = x;
    }

    double obtemY() const {
        return py;
    }

    void defineY(double y){ 
        py = y;
    }

    double obtemRaio() const {
        return raio;
    }

    void defineRaio(double r){ 
        raio = r;
    }

    void escala(double e){
        raio = raio * e;
    }

    string str() const {
        stringstream ss;
        ss << "(" << px << "," << py << ")" << "[" << raio << "]";
        return ss.str();
    }

    double area(){
        return _area();
    }

    double circunferencia(){
        return _circunferencia();
    }

    friend ostream &operator<<(ostream &out, const Circulo &c);
    friend istream &operator>>(istream &in, Circulo &c);
};

ostream &operator<<(ostream &out, const Circulo &c){
    out << c.str();
    return out;
}

istream &operator>>(istream &in, Circulo &c){
    in >> c.px >> c.py >> c.raio;
    return in;
}

int main(){
    Circulo a,b(2), c(2, 3), d(1, 2, 3);

    cout << "a:" << a << " area = " << a.area() << ", cicunferencia = " << a.circunferencia() << endl;
    cout << "b:" << b << " area = " << b.area() << ", cicunferencia = " << b.circunferencia() << endl;
    cout << "c:" << c << " area = " << c.area() << ", cicunferencia = " << c.circunferencia() << endl;
    cout << "d:" << d << " area = " << d.area() << ", cicunferencia = " << d.circunferencia() << endl;

    return 0;
}
