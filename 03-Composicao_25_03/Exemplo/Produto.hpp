// Produto.hpp (Roland Teodorowitsch; 5 abr. 2022)
#ifndef _PRODUTO_HPP_
#define _PRODUTO_HPP_

#include "Data.hpp"
#include <string>
#include <sstream>

using namespace std;

class Produto{
  private:
    int codigo;
    string descricao;
    Data validade;

  public:
    Produto(int cod, string descr, const Data &val);
    int getCodigo();
    string getDescricao();
    Data getValidade();
    string str();
};

#endif
