#ifndef _ALUNO_HPP
#define _ALUNO_HPP

#include <string>

#define MAX_PRESENCAS 100

using namespace std;

class Aluno {
private:
  string nome;
  int numPresencas;
  char presencas[MAX_PRESENCAS];
public:
  Aluno(string n = "");
  ~Aluno();
  string obtemNome();
  void defineNome(string n);
  int obtemNumPresencas();
  void limpaPresencas();
  bool obtemPresenca(int d, char &p);
  string str();
  bool definePresenca(int d, char p);
  bool registraPresenca(char p);
};
#endif
