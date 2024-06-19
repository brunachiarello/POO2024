#include <iostream>
#include <vector>
#include "Artista.cpp"
#include "Filme.cpp"

using namespace std;

void consulta(int tipo){

}

void cadastro(int tipo){

}

int main(){
    vector<string> filmes;
    while(1){
        cout << "---------- MENU ----------" << endl;
        cout << "1- Consulta" << endl;
        cout << "2- Cadastro" << endl;
        cout << "--------------------------" << endl;

        int menu = 0;
        cin >> menu;

        if(menu == 1){
            cout << "selecionado: Consulta" << endl;
            cout << "-------- CONSULTA --------" << endl;
            cout << "1- Ator" << endl;
            cout << "2- Diretor" << endl;
            cout << "3- Filme" << endl;
            cout << "--------------------------" << endl;
            int menuConsulta = 0;
            cin >> menuConsulta;

        } else if(menu == 2){
            cout << "selecionado: Cadastro" << endl;
            cout << "-------- CADASTRO --------" << endl;
            cout << "1- Ator" << endl;
            cout << "2- Diretor" << endl;
            cout << "3- Filme" << endl;
            cout << "--------------------------" << endl;

        } else if(menu == -1){
            break;
        } else {
            throw "Número inválido!"
            break;
        } 
    }


    return 0;
}