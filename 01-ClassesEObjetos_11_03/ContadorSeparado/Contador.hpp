// Contador .hpp
#ifndef _CONTADOR_HPP
#define _CONTADOR_HPP

using namespace std;

class Contador
{
private:
    int valor;

public:
    Contador(int v = 0);
    ~Contador();
    int obtemValor();
    void incrementa();
    void defineValor(int v);
};
#endif
