#include <iostream>
#include <iomanip>

using namespace std;

class Cliente {
protected:
    string nome, pais, dataCadastro;
public:
    Cliente(string n = "", string p = "", string dC = "") {
        nome = n;
        pais = p;
        dataCadastro = dC;
    }

    string obtemNome(){
        return nome;
    }

    void defineNome(string n){
        nome = n;
    }

    string obtemPais(){
        return pais;
    }

    void definePais(string p){
        pais = p;
    }

    string obtemDataCadastro(){
        return dataCadastro;
    }

    void defineDataCadastro(string dC){
        dataCadastro = dC;
    }
};

class PessoaFisica : public Cliente {
private:
    string cpf;
public:
    PessoaFisica(string n = "", string p = "", string dC = "", string CPF = "") : Cliente(n, p, dC){
        cpf = CPF;
    }

    string obtemCPF(){
        return cpf;
    }

    void defineCPF(string CPF){
        cpf = CPF;
    }
};

class PessoaJuridica : public Cliente {
private:
    string cnpj, inscricaoEstadual;
public:
    PessoaJuridica(string n = "", string p = "", string dC = "", string CNPJ = "", string iE = "") : Cliente(n, p, dC) {
        cnpj = CNPJ;
        inscricaoEstadual = iE;
    }

    string obtemCNPJ(){
        return cnpj;
    }

    void defineCNPJ(string CNPJ){
        cnpj = CNPJ;
    }

    string obtemInscricaoEstadual(){
        return inscricaoEstadual;
    }

    void defineInscricaoEstadual(string iE){
        inscricaoEstadual = iE;
    }
};

void imprimeCliente(Cliente *c) {
    cout << "Nome: " << c->obtemNome() << endl;
    cout << "Pais: " << c->obtemPais() << endl;
    cout << "Data de Cadastro: " << c   ->obtemDataCadastro() << endl;
    cout << "----------" << endl;
}

void imprimePessoaFisica(PessoaFisica *pF) {
    cout << "Nome: " << pF->obtemNome() << endl;
    cout << "Pais: " << pF->obtemPais() << endl;
    cout << "Data de Cadastro: " << pF->obtemDataCadastro() << endl;
    cout << "CPF: " << pF->obtemCPF() << endl;
    cout << "----------" << endl;
}

void imprimePessoaJuridica(PessoaJuridica *pJ) {
    cout << "Nome: " << pJ->obtemNome() << endl;
    cout << "Pais: " << pJ->obtemPais() << endl;
    cout << "Data de Cadastro: " << pJ->obtemDataCadastro() << endl;
    cout << "CNPJ: " << pJ->obtemCNPJ() << endl;
    cout << "Inscricao Estadual: " << pJ->obtemInscricaoEstadual() << endl;
    cout << "----------" << endl;
}

int main() {
    Cliente c1("Cliente 1","Brasil","01/01/2001");
    imprimeCliente(&c1);
    Cliente c2;
    imprimeCliente(&c2);
    c2.defineNome("Cliente 2");
    imprimeCliente(&c2);
    c2.definePais("Uruguai");
    imprimeCliente(&c2);
    c2.defineDataCadastro("02/02/2002");
    imprimeCliente(&c2);
    
    PessoaFisica pf3("Pessoa Fisica 3","Brasil","03/03/2003","333.333.333-33");
    imprimePessoaFisica(&pf3);
    PessoaFisica pf4;
    imprimePessoaFisica(&pf4);
    pf4.defineNome("Pessoa Fisica 4");
    imprimePessoaFisica(&pf4);
    pf4.definePais("Paraguai");
    imprimePessoaFisica(&pf4);
    pf4.defineDataCadastro("04/04/2004");
    imprimePessoaFisica(&pf4);
    pf4.defineCPF("444.444.444-44");
    imprimePessoaFisica(&pf4);

    PessoaJuridica pj5("Pessoa Juridica 5","Brasil","05/05/2005","55.555.555/5555-55","55.555555-5");
    imprimePessoaJuridica(&pj5);
    PessoaJuridica pj6;
    imprimePessoaJuridica(&pj6);
    pj6.defineNome("Pessoa Juridica 6");
    imprimePessoaJuridica(&pj6);
    pj6.definePais("Chile");
    imprimePessoaJuridica(&pj6);
    pj6.defineDataCadastro("06/06/2006");
    imprimePessoaJuridica(&pj6);
    pj6.defineCNPJ("66.666.666/6666-66");
    imprimePessoaJuridica(&pj6);
    pj6.defineInscricaoEstadual("66.666666-6");
    imprimePessoaJuridica(&pj6);

    return 0;
}
