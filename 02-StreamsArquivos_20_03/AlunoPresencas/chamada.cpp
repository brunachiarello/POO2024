#include <iostream>
#include <iomanip>
#include <fstream>
#include "Aluno.hpp"

#define MAX_ALUNOS 50

using namespace std;

int main() {
  char presenca;

  ifstream fin("chamada.txt", ios::in);  // LEITURA
  if (!fin.is_open()) { cerr << "Impossivel abrir arquivo 'chamada.txt'..." << endl;  return 1; }
  int numAlunos, numPresencas;
  fin >> numAlunos >> numPresencas;
  Aluno alunos[MAX_ALUNOS]; // 50 alunos serao criados (construtor chamado 50 vezes)
  for (int i=0; i<numAlunos; ++i) {
      string nome;
      fin >> nome;
      alunos[i].defineNome(nome);
      alunos[i].limpaPresencas();
      for (int j=0; j<numPresencas; ++j) {
          fin >> presenca;
          alunos[i].registraPresenca(presenca);
      }
  }
  fin.close();

  for (int i=0; i<numAlunos; ++i) {  // CHAMADA
      cout << alunos[i].obtemNome() << " (P/F)? ";
      cin >> presenca;
      alunos[i].registraPresenca(p);
  }
  ++numPresencas;	

  for (int i=0; i<numAlunos; ++i) {  // RELATORIO
      int dias =  alunos[i].obtemNumPresencas(), p = 0, f = 0;
      for (int j=0; j<dias; ++j) {
          alunos[i].obtemPresenca(j,presenca);
          if ( presenca == 'P' ) ++p;
          else if (presenca = 'F' ) ++f;
      }
      double perc = 100.0 * p / dias;
      cout << alunos[i].obtemNome() << " / presencas=" << p << " / faltas=" << f;
      cout << " / perc=" << fixed << setprecision(2) << perc << endl;
  }

  ofstream fout("chamada2.txt", ios::out);  // ESCRITA
  if (!fout.is_open()) { cerr << "Impossivel abrir arquivo 'chamada2.txt'..." << endl; return 1; }
  fout << numAlunos << " " << numPresencas << endl;
  for (int i=0; i<numAlunos; ++i) fout << alunos[i].str() << endl;
  fout.close();

  return 0;
}
