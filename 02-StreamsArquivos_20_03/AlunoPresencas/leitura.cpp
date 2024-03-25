#include <fstream>   // para usar file streams (ifstream, ofstream)
#include <iostream>  // para usar cin, cout
#include <string>    // para usar string
#include <iomanip>   // para usar manip. (setw, right, ...)
#include <cstdlib>   // para usar srand(), rand() e exit()
#include <ctime>     // para usar time()

using namespace std;

int main() {
  ifstream arq; // Cria input file stream (ifstream)
  cout << "Abrindo arquivo texto..." << endl;
  arq.open( "teste.txt" , ios::in ); // Abre arquivo
  if (!arq.is_open()) return 1; // Se houver erro, sai do programa
  string cabecalho;
  getline(arq,cabecalho); // Le cabecalho
  cout << cabecalho << endl; // Exibe cabecalho na tela
  do { // Le n registros numericos
     int num, valor;
     arq >> num >> valor;
     if (!arq.fail()) cout << num << " " << valor << endl;
  }  while (arq.good());
  if (arq.bad() || !arq.eof()) { // Aborta programa
     cerr << "Erro fatal!" << endl;  arq.close();  exit(1);
  }
  cout << "Fechando o arquivo..." << endl;
  arq.close();
  return 0;
}
