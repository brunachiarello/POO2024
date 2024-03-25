#ifdef DEBUG
#include <iostream>
#endif
#include <sstream>
#include "Aluno.hpp"

Aluno::Aluno(string n) {
  nome = n;
  numPresencas = 0;
  #ifdef DEBUG
  cout << "+ Aluno (" << nome << ") criado..." << endl;
  #endif
}

Aluno::~ Aluno() {
  #ifdef DEBUG
  cout << "- Aluno (" << nome << ") destruido..." << endl;
  #endif
}

string Aluno::obtemNome() { return nome; }
void Aluno::defineNome(string n) { nome = n; }
int Aluno::obtemNumPresencas() { return numPresencas; }
void Aluno::limpaPresencas() { numPresencas = 0; }

bool Aluno::obtemPresenca(int d, char &p) {
  if (d < 0 || d >= numPresencas) return false;
  p = presencas[d];
  return true;
}

string Aluno::str() {
  stringstream ss;
  ss << nome;
  for (int i=0; i<numPresencas; ++i) ss << " " << presencas[i];
  return ss.str();
}

bool Aluno::definePresenca(int d, char p) {
  if (d < 0 || d >= numPresencas) return false;
  presencas[d] = p;
  return true;
}

bool Aluno::registraPresenca(char p) {
  if (numPresencas >= MAX_PRESENCAS) return false;
  presencas[ numPresencas++ ] = p;
  return true;
}

