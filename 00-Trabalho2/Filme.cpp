#include <iostream>
#include "Ator.cpp"
#include "Diretor.cpp"

using namespace std;

class Filme {
private:
    string nomeFilme;
    int anoFilme;
    Ator *atores;
    Diretor *diretores;
public:
    Filme(){}
    Filme(string nF, int aF){
        nomeFilme = nF;
        anoFilme = aF;
    }
    ~Filme(){}
    void definenNomeFilme(string nF){
        nomeFilme = nF;
    }
    string obtemNomeFilme(){
        return nomeFilme;
    }
    void defineAnoFilme(int aF){
        anoFilme = aF;
    }
    int obtemAnoFilme(){
        return anoFilme;
    }
    Diretor *obtemDiretor(){
        return diretores;
    }
    Diretor *defineDiretor(Diretor *d){
        diretores = d;
    }
    int obtemNumAtores(){

    }
    Ator *obtemNomeAtor(){

    }
    .... adicionaAtor(){

    }
    .... removeAtor(){

    }
    .... pesquisaAtor(){

    }
    string str(){

    }


};