#include <iostream>

class Classe{
    
private:
    std::string nome;

public:
    Classe(std::string nome = ""){
        this->nome = nome;
        std::cout << "Construtor chamado para " << nome << std::endl;
    }

    ~Classe(){
        std::cout << "Destrutor chamado para " << nome << std::endl;
    }
};

Classe o1("o1");

int main(){
    Classe *o2;
    Classe o3("o3");
    o2 = new Classe("o2");
    Classe o4;
    delete o2;
    return 0;
}