#include <iostream>

using namespace std;

class Elevador {
private:
    int andarAtual, totalAndares, capacidade, numPessoas;

public:
    Elevador(){
        andarAtual = 0;
        totalAndares = 0;
        capacidade = 0;
        numPessoas = 0;
    }

    Elevador(int cap, int totalAnd){
        capacidade = cap;
        totalAndares = totalAnd;
    }

    ~Elevador(){}

    void entra(){
//        if(capacidade < cap){
//            capacidade++;
//        }
    }

    void sai(){
        if(capacidade > 0){
            capacidade--;
        }
    }

    void sobe(){

    }

    void desce(){

    }

    int obtemAndarAtual(){
        return andarAtual;
    }
    
    int obtemTotalAndares(){
        return totalAndares;
    }
    
    int obtemCapacidade(){
        return capacidade;
    }

    int obtemNumPessoas(){
        return numPessoas;
    }

    void defineTotalAndares(int totalAnd){
        totalAndares = totalAnd;
    }

    void defineCapacidade(int cap){
        capacidade = cap;
    }

    void movimenta(string operacao){
        if(operacao == "^"){
            sobe();

        } else if(operacao == "v"){
            desce();

        } else if(operacao == "+"){
            entra();

        } else if(operacao == "-"){
            sai();
        }
    }
};

int main() {
    Elevador *e;
    int capacidade, totalAndares;
    string operacao;

    // LEITURA
    cin >> capacidade;
    cin >> totalAndares;
    cin >> operacao;

    // TESTE DE FUNCIONAMENTO
    e = new Elevador();
    if ( e->obtemAndarAtual()!=0 || e->obtemCapacidade()!=0 ||
        e->obtemNumPessoas()!=0 || e->obtemTotalAndares()!=0 )
        return 1;

    e->defineCapacidade(capacidade);
    if ( e->obtemAndarAtual()!=0 || e->obtemTotalAndares()!=0 ||
        e->obtemNumPessoas()!=0 || e->obtemCapacidade()!=capacidade )
        return 1;

    e->defineTotalAndares(totalAndares);
    if ( e->obtemAndarAtual()!=0 || e->obtemTotalAndares()!=totalAndares ||
        e->obtemNumPessoas()!=0 || e->obtemCapacidade()!=capacidade )
        return 1;

    for (int i=0; i<=totalAndares+2; ++i) {
        e->sobe();
        if ( e->obtemAndarAtual() > totalAndares ) return 1;
    }

    for (int i=0; i<=totalAndares+2; ++i) {
        e->desce();
        if ( e->obtemAndarAtual() < 0 ) return 1;
    }

    for (int i=0; i<=capacidade+2; ++i) {
        e->entra();
        if ( e->obtemNumPessoas() > capacidade ) return 1;
    }

    for (int i=0; i<=capacidade+2; ++i) {
        e->sai();
        if ( e->obtemNumPessoas() < 0 ) return 1;
    }
    
    // OPERACAO
    e->movimenta(operacao);
    // SAIDA
    cout << e->obtemNumPessoas() << " " << e->obtemAndarAtual() << endl;
    delete e;
    return 0;
}