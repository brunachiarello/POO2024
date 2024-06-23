#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Diretor {
private:
    string nomeDiretor;
    vector<string> filmes;
public:
    Diretor(){} // Construtor vazio
    Diretor(string nD){ // Construtor que recebe o nome do diretor
        nomeDiretor = nD;
    }
    void defineNomeDiretor(string nD){ // Alterar o nome do diretor
        nomeDiretor = nD;
    }
    string obtemNomeDiretor(){ // Obter nome do diretor
        return nomeDiretor;
    }
    void adicionaFilme(string filme){ // Adicionar filme
        filmes.push_back(filme);
    }
    vector<string> obtemFilmes(){ // Obter filme
        return filmes;
    }
};