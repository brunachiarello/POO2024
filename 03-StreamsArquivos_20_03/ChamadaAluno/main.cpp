#include <iostream>
#include <fstream>
#include "Aluno.hpp"

using namespace std;

#define MAX_ALUNOS 60

int main() {
  /*
  Aluno aluno("Joaozinho");
  aluno.adicionaPresenca('P');
  aluno.adicionaPresenca('P');
  aluno.adicionaPresenca('P');
  aluno.adicionaPresenca('F');
  aluno.adicionaPresenca('P');
  cout << aluno.str() << endl;
  */
  
  Aluno *alunos[MAX_ALUNOS];
  int numAlunos = 0;

  // LEITURA
  //ifstream arq;
  //arq.open("chamada.txt", ios::in);
  ifstream arq("chamada.txt");
  if ( !arq.is_open() ) {
     cerr << "ERRO: impossível abrir arquivo \"chamada.txt\"..." << endl;
     return 1;
  }
  int numChamadas;
  arq >> numAlunos >> numChamadas;
  for (int i=0; i<numAlunos; ++i) {
      string nome;
      char pres;
      arq >> nome;
      Aluno *novo = new Aluno(nome);
      for (int j=0; j<numChamadas; ++j) {
          arq >> pres;
          novo->adicionaPresenca(pres);
      }
      alunos[i] = novo;
  }
  arq.close();
  
  // CHAMADA
  for (int i=0; i<numAlunos; ++i) {
      char pres;
      // Chamada de hoje
      cout << alunos[i]->obtemNome() << " (P/F): ";
      cin >> pres;
      alunos[i]->adicionaPresenca(pres);
  }
  
  // EXIBIÇÃO
  for (int i=0; i<numAlunos; ++i) {
      cout << alunos[i]->str() << endl;
  }
  
  // ESCRITA
  // ofstream arqOut;
  // arqOut.open("nova_chamada.txt",ios::out);
  ofstream arqOut("nova_chamada.txt");
  
  if ( !arqOut.is_open() ) {
     cerr << "ERRO: impossível abrir arquivo \"nova_chamada.txt\"..." << endl;
     return 1;
  }
  for (int i=0; i<numAlunos; ++i) {
      arqOut << alunos[i]->str() << endl;
  }
  arqOut.close();

  // DESALOCAÇÃO
  for (int i=0; i<numAlunos; ++i)
      delete alunos[i];
 
  return 0;
}
