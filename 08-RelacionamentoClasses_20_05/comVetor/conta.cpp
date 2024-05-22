// Conta.cpp (Roland Teodorowitsch; 6 out. 2019)

#ifdef DEBUG
#include <iostream>
#endif
#include "Conta.hpp"

Conta::Conta(int numero, double saldo){
  this->numero = numero;
  this->saldo = saldo;
#ifdef DEBUG
  cout << "+ Conta " << numero << " criada..." << endl;
#endif
}

Conta::~Conta(){
#ifdef DEBUG
  cout << "- Conta " << numero << " destruída..." << endl;
#endif
}

int Conta::obtemNumero() const {
  return numero;
}

double Conta::obtemSaldo() const {
  return saldo;
}

void Conta::depositar(double valor){
  saldo += valor;
}

double Conta::retirar(double valor){
  double retirado = 0;
  if (valor <= saldo){
     saldo -= valor;
     retirado = valor;
  }
  return retirado; // nao retira nada, caso nao haja saldo
}

double Conta::retirar(){
  return retirar(saldo); //retira todo o saldo
}
