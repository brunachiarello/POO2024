// main.cpp (Roland Teodorowitsch; 5 abr. 2022)

#include <iostream>
#include "Data.hpp"
#include "Produto.hpp"

using namespace std;

int main(){

  // Cria um objeto Data e ja ajusta os seus atributos
  Data d1(5,5,2007);

  Produto p1(56,"Bolo de chocolate", d1);
 
  // Alternativa: cria-se um objeto "anonimo" na propria chamada
  // ao construtor de Produto
  Produto p2(57,"bolo de cenoura", Data(12,7,2007));

  // Escreve os dados de p1 e p2
  cout << p1.str() << endl;
  cout << p2.str() << endl;
	
  return 0;
}
