#ifndef _ATORES_HPP
#define _ATORES_HPP

#include <string>

using namespace std;

class Atores {
private:
    string nome;
public:
    Atores(){}
    Atores(string n = ""){}
    void defineNome(string n){ nome = n; }
    string obtemNome(){ return nome; }
};

#endif