#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Diretor.cpp"
#include "Ator.cpp"

using namespace std;

class Filme {
private:
    string nomeFilme;
    int anoFilme;
    vector<Ator*> atores; // Vetor de ponteiros para atores
    Diretor *diretor; // Ponteiro para o diretor do filme
public:
    Filme(){
        anoFilme = 0;
        diretor = nullptr;
    }

    Filme(string nF, int aF){
        nomeFilme = nF;
        anoFilme = aF;
        diretor = nullptr;
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
        return diretor;
    }

    void defineDiretor(Diretor *d){
        diretor = d;
    }

    int obtemNumAtores(){
        return atores.size();
    }

    string obtemNomeAtor(int indice){
        if (indice >= 0 && indice < atores.size()) {
            return atores[indice]->obtemNomeAtor();
        }
        return "";
       
    }

    void adicionaAtor(Ator *ator){
        if (atores.size() < 10) {
            atores.push_back(ator);
        } else {
            cerr << "Máximo de atores atingido!" << endl;
        }
        
    }

    void removeAtor(Ator *ator){
        auto it = remove(atores.begin(), atores.end(), ator);
        if (it != atores.end()) {
            atores.erase(it);
        }
    }

    Ator *pesquisaAtor(string nome) {
        for (const auto& ator : atores) {
            if (ator->obtemNomeAtor() == nome) {
                return ator;
            }
        }
        return nullptr;
    }
    
    string str(){
        stringstream ss;
        ss << "Filme: " << nomeFilme << " (" << anoFilme << anoFilme << ")" << endl;
        ss << "Diretor: " << (diretor ? diretor->obtemNomeDiretor() : "N/A") << endl;
        ss << "Atores: " << endl;
        for (const auto& ator : atores) {
            ss << "- " + ator->obtemNomeAtor() << endl;
        }
        return ss.str();
    }
};