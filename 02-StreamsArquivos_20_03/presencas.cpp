#include <iostream>
#include <sstream>
#include <string>

#define MAX_PRESENCAS 80

using namespace std;

class Aluno{
private:
    string nome;
    char presencas[MAX_PRESENCAS];
    int numPresencas;
public:
    Aluno(string n = "");
    ~Aluno();
    string obtemNome();
    void defineNome(string n);
    bool adcionaPresanca(char p){
        if(numPresencas >= MAX_PRESENCAS){
            return false;
        }
        presencas[numPresencas++] = p;
        return true;
    }
    char obtemPresenca(int i);
    int obtemNumPresencas();
    string str();
};

int main(){
    return 0;
}