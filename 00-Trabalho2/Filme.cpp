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
        diretor = nullptr;
    }

    Filme(string nF, int aF){
        nomeFilme = nF;
        anoFilme = aF;
        diretor = nullptr;
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

    void defineDiretor(Diretor *d){
        diretor = d;
    }

    int obtemNumAtores(){
        return numAtores;
    }

    string obtemNomeAtor(int indice){
        if(indice >= 0 && indice < numAtores) {
            return atores[indice]->obtemNomeAtor();
        } else {
            return "";  
        }
       
    }

    void adicionaAtor(Ator *ator){
        if(numAtores < MAX_ATORES){
            atores[numAtores + 1] = ator;
            numAtores++;
        } else {
            cout << "Número máximo de atores atingidos!";
        }
        
    }

    void removeAtor(int indice){
        if (indice >= 0 && indice < numAtores) {
            delete atores[indice];
        for (int i = indice; i < numAtores - 1; i++) {
            atores[i] = atores[i + 1];
        }
        numAtores--;
        }
    }

    Ator *pesquisaAtor(string nome) {
        for(int i = 0; i < numAtores; i++) {
            if(atores[i]->obtemNomeAtor() == nome) {
                return atores[i];
            }
        }
        return nullptr; 
    }
    
    string str(){

    }
};