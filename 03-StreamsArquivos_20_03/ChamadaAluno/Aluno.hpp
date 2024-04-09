// Aluno.hpp

#ifndef _ALUNO_HPP
#define _ALUNO_HPP

#include <string>

#define MAX_PRESENCAS 80

using namespace std;

class Aluno {
private:
  string nome;
  char presencas[MAX_PRESENCAS];
  int numPresencas;
public:
  Aluno(string n="");
  ~Aluno();
  string obtemNome();
  void defineNome(string n);
  bool adicionaPresenca(char p);
  char obtemPresenca(int i);
  int obtemNumPresencas();
  string str();
};

#endif
