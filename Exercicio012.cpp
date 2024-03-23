#include <iostream>
#include <iomanip>

#define MAX 10

using namespace std;

class Estudante {
private:
    string nome;
    double nota[MAX]; 
    int numNotas;

public:
    Estudante(){
        nome = {};
        for(int i = 0; i < MAX; i++){
            nota[i] = 0;
        }
        numNotas = 0;
    }

    Estudante(string n){
        nome = n;
        for(int i = 0; i < MAX; i++){
            nota[i] = 0;
        }
        numNotas = 0;
    }

    ~Estudante(){}

    void defineNome(string n){
        nome = n;
    }

    string obtemNome(){
        return nome;
    }

    bool adicionaNota(double nt){
        if(numNotas < MAX){
            nota[numNotas] = nt;
            numNotas++;
            return true;
        }
        return false;      
    }

    int obtemNumNotas(){
        return numNotas;
    }

    double obtemNota(int indice){
        if(indice >= 0 && indice <= MAX - 1){
            return nota[indice];
        }
        return -1.0000;
    }

    double obtemMedia(){
        if(numNotas == 0){
            return -1.0000;
        }
        double soma = 0;
        for(int i = 0; i < numNotas; i++){
            soma += nota[i];
        }
        return soma / numNotas;
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
