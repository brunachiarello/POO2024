#include <iostream>

using namespace std;

class Ator {
private:
    string nomeAtor;
public:
    Ator(){}
    ~Ator(){}
    void defineNomeAtor(string nA){
        nomeAtor = nA;
    }
    string obtemNomeAtor(){
        return nomeAtor;
    }
};

