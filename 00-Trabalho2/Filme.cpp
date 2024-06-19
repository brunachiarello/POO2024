#include <iostream>
#include "Diretor.cpp"
#include "Ator.cpp"

#define MAX_ATORES 10

using namespace std;

class Filme {
private:
    string nomeFilme;
    int anoFilme;
    Ator *atores[MAX_ATORES];
    int numAtores;
    Diretor *diretor;
public:
    Filme(){
        numAtores = 0;
        diretores = nullptr;
    }

    Filme(string nF, int aF){
        nomeFilme = nF;
        anoFilme = aF;
        diretores = nullptr;
    }

    ~Filme(){
        for(int i = 0; i < numAtores; i++){
            delete atores[i];
        }
    }

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
        return diretor;
    }

    Diretor *defineDiretor(Diretor *d){
        diretor = d;
    }

    int obtemNumAtores(){
        return numAtores;
    }

    string obtemNomeAtor(){
        
    }

    void adicionaAtor(Ator *ator){
        if(numAtores < MAX_ATORES){
            atores[numAtores + 1] = ator;
            numAtores++;
        } else {
            throw "Número máximo de atores atingido!";
        }
        
    }

    void removeAtor(Ator *ator){

    }

    Ator *pesquisaAtor(string nome) const {

    }
    
    string str(){

    }


};