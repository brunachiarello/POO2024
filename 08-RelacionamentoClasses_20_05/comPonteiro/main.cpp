// main.cpp (Roland Teodorowitsch; 6 out. 2019)

#include <iostream>
#include <iomanip>
#include "Banco.hpp"
#include "Conta.hpp"

using namespace std;

int main(){
  cout << "Criando banco1 com construtor padrão..." << endl;

  Banco *b = new Banco("Superbanco");
  cout << endl;

  cout << "Testando registro do nome do banco..." << endl;
  cout << "Nome esperado: Superbanco" << endl;
  cout << "Nome: " << b->obtemNome() << endl;
  cout << endl;

  cout << "Testando adição de contas..." << endl;
  b->adicionaConta(Conta(1001));
  b->adicionaConta(Conta(1002));
  b->adicionaConta(Conta(1003,100.0));

  cout << "Numero de contas esperado: 3" << endl;
  cout << "Numero de contas inserido: " << b->obtemNumContas() << endl;
  cout << endl;	

  cout << "Testando obtem contas..." << endl;
  Conta *c1002 = b->obtemConta(1002);
  Conta *c1001 = b->obtemConta(1001);
  Conta *c1003 = b->obtemConta(1003);

  cout << "Testando depósito..." << endl;
  c1002->depositar(10000.0);
  c1001->depositar(1000.0);
  c1003->depositar(100.0);

  cout << fixed << setprecision(1);
  cout << "Saldo esperado na conta 1002: 10000.0" << endl;
  cout << "Saldo na conta 1002: " << c1002->obtemSaldo() << endl;
  cout << "Saldo esperado na conta 1001: 1000.0" << endl;
  cout << "Saldo na conta 1001: " <<  c1001->obtemSaldo() << endl;
  cout << "Saldo esperado na conta 1003: 200.0" << endl;
  cout << "Saldo na conta 1003: " <<  c1003->obtemSaldo() << endl;
  cout << endl;

  cout <<"Testando retirada..." << endl;
  double retirado1 = c1002->retirar();
  double retirado2 = c1001->retirar(200);

  cout << "Saldo esperado na conta 1002: 0.0" << endl;
  cout << "Saldo na conta 1002: " <<  c1002->obtemSaldo() << endl;
  cout << "Saldo RETIRADO esperado da conta 1002: 10000.0" << endl;
  cout << "Saldo RETIRADO da conta 1002: " <<  retirado1 << endl;
  cout << "Saldo esperado na conta 1001: 800.0" << endl;
  cout << "Saldo na conta 1001: " <<  c1001->obtemSaldo() << endl;
  cout << "Saldo RETIRADO esperado da conta 1001: 200.0" << endl;
  cout << "Saldo RETIRADO da conta 1001: " <<  retirado2 << endl;
  cout << endl;

  cout << "Testando transferência..." << endl;
  bool transferido = b->transferir(*c1001,*c1002,500.0);

  cout << "Transeferido? Esperado: true; Resultado: " << transferido << endl;
  if (transferido){
     cout << "Saldo esperado na conta 1002: 500.0" << endl;
     cout << "Saldo na conta 1002: " <<  c1002->obtemSaldo() << endl;
     cout << "Saldo esperado na conta 1001: 300.0" << endl;
     cout << "Saldo na conta 1001: " <<  c1001->obtemSaldo() << endl;
  }
  cout << endl;

  cout << "Testando saldo total..." << endl;
  cout << "Saldo total esperado: 1000.0" << endl;
  cout << "Saldo total: " <<  b->obtemSaldoTotal() << endl;

  delete b;

  return 0;
}