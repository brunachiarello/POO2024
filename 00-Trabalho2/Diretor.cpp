#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Diretor {
private:
    string nomeDiretor;
    vector<string> filmes;
public:
    Diretor(){}
    ~Diretor(){}
    void defineNomeDiretor(string nD){
        nomeDiretor = nD;
    }
    string obtemNomeDiretor(){
        return nomeDiretor;
    }
    void adicionaFilme(string filme){
        filmes.push_back(filme);
    }
    vector<string> obtemFIlmes(){
        return filmes;
    }
};