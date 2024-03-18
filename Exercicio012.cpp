#include <iostream>

using namespace std;

class Estudante {
private:
    string nome;
    int nota[10]; // vetor parcialmente preenchido ***********
    int numNotas;

public:
    Estudante(){
        nome = {};
        nota[10] = {0}; // ***********
    }

    Estudante(string n, int nt[10]){
        nome = n;
        nt[10] = 0; // *********
    }

    ~Estudante(){}

    void defineNome(string n){
        nome = n;
    }

    string obtemNome(){
        return nome;
    }

    bool adcionaNota(){
        numNotas++;
        return true;
    }

    int obtemNumNotas(){
        return numNotas;
    }

    int obtemNota(){
        return nota[10];
    }

    int obtemMedia(){
        for(int i = 0; i < numNotas; i++){
            
        }
    }

};

int main(){
    return 0;
}