// Data.cpp (Roland Teodorowitsch; 5 abr. 2022)

#include "Data.hpp"

Data::Data(int udia, int umes, int uano){
  dia = udia;
  mes = umes;
  ano = uano;
}

int Data::getDia(){
  return dia;
}

int Data::getMes(){
  return mes;
}

int Data::getAno(){
  return ano;
}

void Data::setDia(int d){
  dia = d;
}

void Data::setMes(int m){
  mes = m;
}

void Data::setAno(int a){
  ano = a;
}

string Data::str(){
  stringstream tmp;
  tmp << dia << ";" << mes << ";" << ano;
  return tmp.str();
}
