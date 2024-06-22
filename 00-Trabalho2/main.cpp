#include <iostream>
#include <fstream>
#include <vector>
#include "Filme.cpp"

using namespace std;

void consulta(int tipo){
    if(tipo == 1){

    } else if(tipo == 2){

    } else if(tipo == 3){

    }
}

void cadastro(int tipo){
    if(tipo == 1){

    } else if(tipo == 2){

    } else if(tipo == 3){
        
    }
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

            cout << "-------- CONSULTA --------" << endl;
            cout << "1- Ator" << endl;
            cout << "2- Diretor" << endl;
            cout << "3- Filme" << endl;
            cout << "--------------------------" << endl;
            int menuConsulta = 0;
            cin >> menuConsulta;

            if(menuConsulta == 1 || menuConsulta == 2 || menuConsulta == 3){
                consulta(menuConsulta);
            } else {
                break;
            }

        } else if(menu == 2){

            cout << "-------- CADASTRO --------" << endl;
            cout << "1- Ator" << endl;
            cout << "2- Diretor" << endl;
            cout << "3- Filme" << endl;
            cout << "--------------------------" << endl;
            int menuCadastro = 0;
            cin >> menuCadastro;

            if(menuCadastro == 1 || menuCadastro == 2 || menuCadastro == 3){
                consulta(menuCadastro);
            } else {
                break;
            }

        } else {
            break;
        } 
    }
    return 0;
}