// Produto.cpp (Roland Teodorowitsch; 5 abr. 2022)

#include "Produto.hpp"

Produto::Produto(int cod, string descr, const Data &val){
  codigo = cod;
  descricao = descr;
  validade = val;
}

int Produto::getCodigo(){
  return codigo;
}

string Produto::getDescricao(){
  return descricao;
}

Data Produto::getValidade(){
  return validade;
}

string Produto::str(){
  stringstream tmp;
  tmp << codigo << ";" << descricao << ";" << validade.str();
  return tmp.str();
}
