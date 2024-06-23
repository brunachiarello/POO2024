#include <iostream>
#include <fstream>
#include <vector>
#include "Filme.cpp"

using namespace std;

void lerArquivo(const string& nomeArquivo, vector<string>& dados) {
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            dados.push_back(linha);
        }
        arquivo.close();
    }
}

void escreverArquivo(const string& nomeArquivo, const vector<string>& dados) {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const string& linha : dados) {
            arquivo << linha << endl;
        }
        arquivo.close();
    }
}

int main(){
    vector<Filme> filmes;
    vector<Ator> atores;
    vector<Diretor> diretores;

    lerArquivo("BD_Atores.txt");
    lerArquivo("BD_Diretores.txt");

    cout << "---------- MENU ----------" << endl;
    cout << "Consulta" << endl;
    cout << "1- de atores" << endl;
    cout << "2- de diretores" << endl;
    cout << "3- de filmes" << endl;
    cout << "Cadastro" << endl;
    cout << "4- de atores" << endl;
    cout << "5- de diretores" << endl;
    cout << "6- de filmes" << endl;
    cout << "--------------------------" << endl;

    int menu = 0;
    cin >> menu;

    escreverArquivo("BD_Atores.txt");
    escreverArquivo("BD_Diretores.txt");

    return 0;
}