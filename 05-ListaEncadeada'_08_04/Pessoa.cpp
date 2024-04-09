#include <sstream>
#include "Pessoa.hpp"

Pessoa::Pessoa(string n, string e) {
  nome = n;
  endereco = e; 
}

string Pessoa::obtemNome() { return nome; }
void Pessoa::defineNome(string n) { nome = n; }
string Pessoa::obtemEndereco() { return endereco; }
void Pessoa::defineEndereco(string e) { endereco = e; }

string Pessoa::str() {
  stringstream ss;
  ss << nome << endl;
  ss << endereco << endl;
  return ss.str();
}

