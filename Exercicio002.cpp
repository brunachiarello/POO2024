#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

#define MAX_FUNCIONARIOS 10

class Funcionario { /* implementacao da classe Funcionario */ };

class Empresa { /* implementacao da classe Empresa */ };

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
