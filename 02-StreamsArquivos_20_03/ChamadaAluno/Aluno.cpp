// Aluno.cpp

#include <sstream>
#ifdef DEBUG
#include <iostream>
#endif
#include "Aluno.hpp"

Aluno::Aluno(string n) {
  nome = n;
  numPresencas = 0;
  #ifdef DEBUG
  cout << "+ Aluno(" << nome << ") criado..." << endl;
  #endif
}

Aluno::~Aluno() {
  #ifdef DEBUG
  cout << "- Aluno(" << nome << ") destruído..." << endl;
  #endif
}

string Aluno::obtemNome() { return nome; }
void Aluno::defineNome(string n) { nome = n; }

bool Aluno::adicionaPresenca(char p) {
  if ( numPresencas >= MAX_PRESENCAS ) return false;
  presencas[numPresencas++] = p;
  return true;
}

char Aluno::obtemPresenca(int i) {
  if (i < 0 || i >= numPresencas) return '\0';
  return presencas[i];
}

int Aluno::obtemNumPresencas() { return numPresencas; }

string Aluno::str() {
  stringstream ss;
  ss << nome;
  for (int i=0; i<numPresencas; ++i)
      ss << " " << presencas[i];
  return ss.str();
}

