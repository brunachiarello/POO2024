#include <iostream>
#include <iomanip>

#define MAX 10

using namespace std;

class Estudante {
private:
    string nome;
    int *nota[MAX]; // vetor parcialmente preenchido ***********
    int numNotas;

public:
    Estudante(){
        nome = {};
        *nota = {0}; // ***********
    }

    Estudante(string n){
        nome = n;
        *nota = 0; // *********
    }

    ~Estudante(){}

    void defineNome(string n){
        nome = n;
    }

    string obtemNome(){
        return nome;
    }

    bool adcionaNota(int *n){
        numNotas++;
        return true;
    }

    int obtemNumNotas(){
        return numNotas;
    }

    int obtemNota(){
        return *nota;
    }

    int obtemMedia(){
        for(int i = 0; i < numNotas; i++){
            
        }
    }
};

void mostraEstudante(Estudante &e) {
  	cout << e.obtemNome() << " [";
    int n = e.obtemNumNotas();
    for (int i=0; i<n; ++i) {
        if (i>0) cout << " ";
        cout << fixed << setprecision(1) << e.obtemNota(i);
    }
    cout << "] = " << fixed << setprecision(4) << e.obtemMedia() << endl;
}

int main() {
  Estudante e1;
  mostraEstudante(e1);
  e1.defineNome("Fulano");
  cout << (e1.adicionaNota(7.0)?"true":"false") << endl;
  cout << (e1.adicionaNota(10.0)?"true":"false") << endl;
  mostraEstudante(e1);
  Estudante e2("Beltrano");
  mostraEstudante(e2);
  double n = 1.0;
  while (e2.adicionaNota(n)) {
        mostraEstudante(e2);
        n = n + 1.0;
  }
  return 0;
}
