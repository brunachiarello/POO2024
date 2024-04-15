#ifndef _PESSOA_HPP
#define _PESSOA_HPP

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
  private:
    string nome, endereco;
  public: 
    Pessoa(string n="", string e="");
    string obtemNome();
    void defineNome(string n);
    string obtemEndereco();
    void defineEndereco(string e);
    string str();
};
#endif
