#include <iostream>

using namespace std;

class Diretor {
private:
    string nomeDiretor;
public:
    Diretor(){}
    ~Diretor(){}
    void defineNomeDiretor(string nD){
        nomeDiretor = nD;
    }
    string obtemNomeDiretor(){
        return nomeDiretor;
    }
};