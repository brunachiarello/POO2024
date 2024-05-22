// Banco.hpp (Roland Teodorowitsch; 6 out. 2019)

#ifndef _BANCO_HPP
#define _BANCO_HPP

#include <string>
#include "Conta.hpp"

#define NUM_MAX_CONTAS 1000

class Banco {
  private:
    string nome;
    Conta contas[NUM_MAX_CONTAS];
    int numContas;
			
  public:
    Banco(string n="");
    ~Banco();
    string obtemNome();
    bool adicionaConta(const Conta &c);
    Conta* obtemConta(int cconta);
    double obtemSaldoTotal();
    bool transferir(Conta &deConta, Conta &paraConta, double valor);
    int obtemNumContas();
};

#endif