#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ator {
private:
    string nomeAtor;
    vector<string> filmes;
public:
    Ator(){} // Construtor vazio
    Ator(string nA){ // Construtor que recebe o nome do ator/atriz
        nomeAtor = nA;
    }
    void defineNomeAtor(string nA){ // Alterar o nome do ator/atriz
        nomeAtor = nA;
    }
    string obtemNomeAtor(){ // Obter o nome do ator/atriz
        return nomeAtor;
    }
    void adicionaFilme(string filme){  // Adicionar filme
        filmes.push_back(filme);
    }
    vector<string> obtemFilmes(){ // Obter filme
        return filmes;
    }
};

