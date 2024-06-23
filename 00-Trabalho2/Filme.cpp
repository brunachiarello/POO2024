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
    vector<Ator*> atores;
    Diretor *diretor; 
public:
    Filme(){ // Construtor vazio
        anoFilme = 0;
        diretor = nullptr;
    }

    Filme(string nF, int aF){ // Construtor que recebe o nome e o ano de lançamento
        nomeFilme = nF;
        anoFilme = aF;
        diretor = nullptr;
    }

    void definenNomeFilme(string nF){ // Alterar o nome do filme
        nomeFilme = nF;
    }

    string obtemNomeFilme(){ // Obter o nome do filme
        return nomeFilme;
    }

    void defineAnoFilme(int aF){ // Alterar o ano de lançamento do filme
        anoFilme = aF;
    }

    int obtemAnoFilme(){ // Obter o ano de lançamento do filme
        return anoFilme;
    }

    Diretor *obtemDiretor(){ // Obter o diretor do filme
        return diretor;
    }

    void defineDiretor(Diretor *d){ // Alterar o diretor do filme
        diretor = d;
    }

    int obtemNumAtores(){ // Obter o número de atores/atrizes
        return atores.size();
    }

    string obtemNomeAtor(int indice){ // Obter nome do ator/atriz
        if (indice >= 0 && indice < atores.size()) {
            return atores[indice]->obtemNomeAtor();
        }
        return "";
       
    }

    void adicionaAtor(Ator *ator){ // Adicionar um ator/atriz
        if (atores.size() < 10) {
            atores.push_back(ator);
        } else {
            cerr << "Máximo de atores atingido!" << endl;
        }
        
    }

    void removeAtor(Ator *ator){ // Remover um ator/atriz
        auto it = remove(atores.begin(), atores.end(), ator);
        if (it != atores.end()) {
            atores.erase(it);
        }
    }

    Ator *pesquisaAtor(string nome) { // Pesquisar se um ator faz parte do elenco do filme
        for (const auto& ator : atores) {
            if (ator->obtemNomeAtor() == nome) {
                return ator;
            }
        }
        return nullptr;
    }
    
    string str(){ // Obter todas as informações do filme
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