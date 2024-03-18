#include <iostream>

using namespace std;

class Estudante {
private:
    string nome;
    int nota[10]; // vetor parcialmente preenchido ***********

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

    }

    int obtemNumNotas(){

    }

    int obtemNota(){

    }

    int obtemMedia(){

    }

};

int main(){
    return 0;
}