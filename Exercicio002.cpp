#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

#define MAX_FUNCIONARIOS 10

class Funcionario { 
private:
    int matriculaFunc;
    string nomeFunc;
    float salarioFunc;
public:
    Funcionario(){
        matriculaFunc = 0;
        nomeFunc = { };
        salarioFunc = 0.0;
    }
    Funcionario(int mFunc, string nFunc, float sFunc){
        matriculaFunc = mFunc;
        nomeFunc = nFunc;
        salarioFunc = sFunc;
    }
    ~Funcionario(){}
    int obtemMatricula(){
        return matriculaFunc;
    }
    string obtemNome(){
        return nomeFunc;
    }
    float obtemSalario(){
        return salarioFunc;
    }
    void defineMatricula(int mFunc){
        matriculaFunc = mFunc;
    }
    void defineNome(string nFunc){
        nomeFunc = nFunc;
    }
    void defineSalario(float sFunc){
        salarioFunc = sFunc;
    }
    string str(){
        stringstream salario;
        string tudo;

        string matricula = to_string(matriculaFunc);
        while (matricula.length() < 10) {
            matricula = "0" + matricula;
        }

        salario << fixed << setprecision(2) << salarioFunc;
        string salario_str = salario.str();

        tudo = nomeFunc + " (" + matricula + "): R$" + salario_str;

        return tudo;
    }
};

class Empresa {
private:
    int numEmp;
    string razaoSocialEmp;
    string CNPJ;
    Funcionario* funcionarios[MAX_FUNCIONARIOS];
    int numFunc;
public:
    Empresa(){
        numEmp = 0;
        razaoSocialEmp = " ";
        CNPJ = "00.000.000/0000-00";
        numFunc = 0;
    }
    Empresa(int nEmp, string rsEmp, string cnpj){
        numEmp = nEmp;
        razaoSocialEmp = rsEmp;
        CNPJ = cnpj;
        numFunc = 0;
    }
    ~Empresa(){ }
    int obtemNumero(){
        return numEmp;
    }
    string obtemRazaoSocial(){
        return razaoSocialEmp;
    }
    string obtemCnpj(){
        return CNPJ;
    }
    Funcionario* obtemFuncionario(int indice){
        if (indice >= 0 && indice < numFunc) {
            return funcionarios[indice];
        } else {
            return nullptr;
        }
    }
    int obtemNumFuncionarios(){
        return numFunc;
    }
    void defineNumero(int nEmp){
        numEmp = nEmp;
    }
    void defineRazaoSocial(string rsEmp){
        razaoSocialEmp = rsEmp;
    }
    void defineCnpj(string cnpj){
        CNPJ = cnpj;
    }
    bool adicionaFuncionario(Funcionario *func){
        if (numFunc < MAX_FUNCIONARIOS) {
            funcionarios[numFunc] = func;
            numFunc++;
            return true;
        } else {
            return false;
        }
    }
    double calculaFolha(){
        double totalS = 0.0;
        for (int i = 0; i < numFunc; ++i) {
            totalS += funcionarios[i]->obtemSalario();
        }
        return totalS;
    }
    string str(){
        stringstream ss;
        ss << numEmp << " - " << razaoSocialEmp << " - CNPJ: " << CNPJ << endl;
        for (int i = 0; i < numFunc; ++i) {
            ss << funcionarios[i]->str() << endl;
        }
        if (numFunc > 0){
            ss << "TOTAL DA FOLHA DE PAGAMENTO = " << fixed << setprecision(2) << calculaFolha() << endl;
        }
        return ss.str();
    }
};

int main() {
    Funcionario *empregado[] = {
        new Funcionario(1,"Benedito Oliveira",1111.11),
        new Funcionario(2,"Carlos Santana",2222.22),
        new Funcionario(3,"Daniela Silva",3333.33),
        new Funcionario(4,"Elisabeth Benedito",4444.44),
        new Funcionario(5,"Fernanda Gonzaga",5555.55),
        new Funcionario(6,"Gilson Souza",6666.66),
        new Funcionario(7,"Heitor Bernardes",7777.77),
        new Funcionario(8,"Irineu Perazzo",8888.88),
        new Funcionario(9,"Joana Cintra",9999.99),
        new Funcionario(10,"Klaus Barth",10101.01),
        new Funcionario(11,"Laura Steiner",12121.21)
    };
    int numEmpregados = sizeof(empregado)/sizeof(Funcionario *);
    Empresa *empresa = new Empresa(0,"SEM NOME","11.111.111/1111-11");
    int e;
    cout << empresa->str() << endl;
    empresa->defineNumero(123);
    empresa->defineRazaoSocial("Empresa Ficticia Ltda.");
    empresa->defineCnpj("68.400.804/0001-11");
    for (e=0; e<5; ++e)
        if (!empresa->adicionaFuncionario(empregado[e])) { cerr << "ERRO"; exit(1); }
    for (e=0; e<5; ++e)
        if (empresa->obtemFuncionario(e) != empregado[e]) { cerr << "ERRO"; exit(1); }
    for (; e<numEmpregados; ++e)
        if (empresa->obtemFuncionario(e) != nullptr) { cerr << "ERRO"; exit(1); }
    cout << empresa->str() << endl;
        for (e=5; e<MAX_FUNCIONARIOS; ++e)
        if (!empresa->adicionaFuncionario(empregado[e])) { cerr << "ERRO"; exit(1); }
    for (; e<numEmpregados; ++e)
        if (empresa->adicionaFuncionario(empregado[e])) { cerr << "ERRO"; exit(1); }
    for (e=0; e<MAX_FUNCIONARIOS; ++e)
        if (empresa->obtemFuncionario(e) != empregado[e]) { cerr << "ERRO"; exit(1); }
    cout << empresa->str() << endl;
    delete empresa;
    for (e=0; e<numEmpregados; ++e)
        delete empregado[e];
    return 0;
}
