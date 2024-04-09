// Data.hpp (Roland Teodorowitsch; 5 abr. 2022)
#ifndef _DATA_HPP_
#define _DATA_HPP_

#include <sstream>
#include <string>

using namespace std;

class Data{
  private:
    int dia, mes, ano;
  public:
    Data(int udia=1, int umes=1, int uano=2012);
    int getDia();
    int getMes();
    int getAno();
    void setDia(int d);
    void setMes(int m);
    void setAno(int a);
    string str();
};

#endif
