// AlunoRegular.hpp (Roland Teodorowitsch; 27 out. 2019)
#ifndef _ALUNOREGULAR_HPP
#define _ALUNOREGULAR_HPP
#include "Aluno.hpp"

class AlunoRegular : public Aluno {
  public:
    AlunoRegular(int m, string n, string c, int s);
    double mensalidade(int parcela);
};
#endif
