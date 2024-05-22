// Banco.cpp (Roland Teodorowitsch; 6 out. 2019)

#ifdef DEBUG
#include <iostream>
#endif
#include "Banco.hpp"

Banco::Banco(string n){
  nome = n;
  numContas = 0;
#ifdef DEBUG
  cout << "+ Banco " << nome << " criado..." << endl;
#endif
}

Banco::~Banco(){
#ifdef DEBUG
    cout << "- Banco " << nome << " destruído..." << endl;
#endif
}

string Banco::obtemNome(){
  return nome;
}

bool Banco::adicionaConta(const Conta &c){
  if (numContas < NUM_MAX_CONTAS) {
     contas[numContas] = c;
     numContas++;
     return true;
  }
  return false;
}

Conta* Banco::obtemConta(int cconta){
  for (int i = 0; i < numContas; i++)
      if (contas[i].obtemNumero() == cconta)
         return &contas[i];
  return nullptr;
}

double Banco::obtemSaldoTotal(){
  double saldoTotal = 0.0;
  for (int i = 0; i < numContas; i++)
      saldoTotal += contas[i].obtemSaldo();
  return saldoTotal;
}

bool Banco::transferir(Conta &deConta, Conta &paraConta, double valor){
  double retirado = deConta.retirar(valor);
  if (retirado == valor){
     paraConta.depositar(valor);
     return true;
  }
  return false;
}

int Banco::obtemNumContas(){
  return numContas;
}
