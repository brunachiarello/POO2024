#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ator {
private:
    string nomeAtor;
    vector<string> filmes;
public:
    Ator(){}
    ~Ator(){}
    void defineNomeAtor(string nA){
        nomeAtor = nA;
    }
    string obtemNomeAtor(){
        return nomeAtor;
    }
    void adicionaFilme(string filme){
        filmes.push_back(filme);
    }
    vector<string> obtemFIlmes(){
        return filmes;
    }
};

