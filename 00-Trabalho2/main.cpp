#include <iostream>
#include <fstream>
#include <vector>
#include "Filme.cpp"

using namespace std;

void consultaFilmes(vector<Filme>& filmes) {
    string nomeFilme;
    cout << "Nome do Filme: ";
    cin.ignore();
    getline(cin, nomeFilme);

    for(auto& filme : filmes) {
        if(filme.obtemNomeFilme() == nomeFilme) {
            cout << filme.str() << endl;
            break;
        }
    }
}

void consultaFilmesPorAtor(vector<Ator>& atores) {
    string nomeAtor;
    cout << "Nome do Ator: ";
    cin.ignore();
    getline(cin, nomeAtor);

    for(auto& ator : atores) {
        if(ator.obtemNomeAtor() == nomeAtor) {
            vector<string> filmesAtor = ator.obtemFilmes();
            for(const auto& filme : filmesAtor) {
                cout << filme << endl;
            }
            break;
        }
    }
}

void consultaFilmesPorDiretor(vector<Diretor>& diretores) {
    string nomeDiretor;
    cout << "Nome do Diretor: ";
    cin.ignore();
    getline(cin, nomeDiretor);

    for(auto& diretor : diretores) {
        if(diretor.obtemNomeDiretor() == nomeDiretor) {
            vector<string> filmesDiretor = diretor.obtemFilmes();
            for(const auto& filme : filmesDiretor) {
                cout << filme << endl;
            }
            break;
        }
    }
}

void cadastroAtor(vector<Ator>& atores) {
    string nome;
    cout << "Nome do Ator: ";
    cin.ignore();
    getline(cin, nome);
    atores.push_back(Ator(nome));
}

void cadastroDiretor(vector<Diretor>& diretores) {
    string nome;
    cout << "Nome do Diretor: ";
    cin.ignore();
    getline(cin, nome);
    diretores.push_back(Diretor(nome));
}

void cadastroFilme(vector<Filme>& filmes, vector<Ator>& atores, vector<Diretor>& diretores) {
    string nomeFilme;
    int ano;
    string nomeDiretor;
    string nomeAtor;

    cout << "Nome do Filme: ";
    cin.ignore();
    getline(cin, nomeFilme);

    cout << "Ano de Lançamento: ";
    cin >> ano;

    Filme filme(nomeFilme, ano);

    cout << "Nome do Diretor: ";
    cin.ignore();
    getline(cin, nomeDiretor);

    for(auto& diretor : diretores) {
        if(diretor.obtemNomeDiretor() == nomeDiretor) {
            filme.defineDiretor(&diretor);
            diretor.adicionaFilme(nomeFilme);
            break;
        }
    }

    cout << "Nome do Ator: ";
    getline(cin, nomeAtor);

    for(auto& ator : atores) {
        if(ator.obtemNomeAtor() == nomeAtor) {
            filme.adicionaAtor(&ator);
            ator.adicionaFilme(nomeFilme);
            break;
        }
    }
    filmes.push_back(filme);
}

void atualizaDiretor(vector<Diretor>& diretores) {
    ofstream arquivo("BD_Diretores.txt");
    if(!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!\n";
        return;
    }

    for(auto& diretor : diretores) {
        arquivo << "#\n";
        arquivo << diretor.obtemNomeDiretor() << "\n";
        for (const auto& filme : diretor.obtemFilmes()) {
            arquivo << "--" << filme << "\n";
        }
    }
    arquivo.close();
}

void atualizaAtor(vector<Ator>& atores) {
    ofstream arquivo("BD_Atores.txt");
    if(!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    for(auto& ator : atores) {
        arquivo << "#\n";
        arquivo << ator.obtemNomeAtor() << "\n";
        for (const auto& filme : ator.obtemFilmes()) {
            arquivo << "--" << filme << "\n";
        }
    }
    arquivo.close();
}

void leDiretor(vector<Diretor>& diretores) {
    ifstream arquivo("BD_Diretores.txt");
    if(!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string linha;
    Diretor* diretorAtual = nullptr;

    while(getline(arquivo, linha)) {
        if(linha.empty()) continue;

        if(linha[0] == '#') {
            if(diretorAtual != nullptr) {
                diretores.push_back(*diretorAtual);
                delete diretorAtual;
                diretorAtual = nullptr;
            }
        } else if(linha[0] == '-') {
            if(diretorAtual != nullptr) {
                string nomeFilme = linha.substr(2, linha.rfind('(') - 3);
                diretorAtual->adicionaFilme(nomeFilme);
            }
        } else {
            diretorAtual = new Diretor(linha);
        }
    }

    if(diretorAtual != nullptr) {
        diretores.push_back(*diretorAtual);
        delete diretorAtual;
    }
    arquivo.close();
}

void leAtor(vector<Ator>& atores) {
    ifstream arquivo("BD_Atores.txt");
    if(!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string linha;
    Ator* atorAtual = nullptr;

    while(getline(arquivo, linha)) {
        if(linha.empty()) continue;

        if(linha[0] == '#') {
            if(atorAtual != nullptr) {
                atores.push_back(*atorAtual);
                delete atorAtual;
                atorAtual = nullptr;
            }
        } else if(linha[0] == '-') {
            if(atorAtual != nullptr) {
                string nomeFilme = linha.substr(2, linha.rfind('(') - 3);
                atorAtual->adicionaFilme(nomeFilme);
            }
        } else {
            atorAtual = new Ator(linha);
        }
    }

    if (atorAtual != nullptr) {
        atores.push_back(*atorAtual);
        delete atorAtual;
    }
    arquivo.close();
}

int main(){
    vector<Filme> filmes;
    vector<Ator> atores;
    vector<Diretor> diretores;

    leDiretor(diretores);
    leAtor(atores);
    
    while(1){
        cout << "---------- MENU ----------" << endl;
        cout << "Consulta" << endl;
        cout << "1- por atores" << endl;
        cout << "2- por diretores" << endl;
        cout << "3- de filmes" << endl;
        cout << "Cadastro" << endl;
        cout << "4- de atores" << endl;
        cout << "5- de diretores" << endl;
        cout << "6- de filmes" << endl;
        cout << "Sair: -1" << endl;
        cout << "--------------------------" << endl;

        int menu = 0;
        cin >> menu;

        if(menu == 1){
            consultaFilmesPorAtor(atores);
        } else if(menu == 2){
            consultaFilmesPorDiretor(diretores);
        } else if(menu == 3){
            consultaFilmes(filmes);
        } else if(menu == 4){
            cadastroAtor(atores);
        } else if(menu == 5){
            cadastroDiretor(diretores);
        } else if(menu == 6){
            cadastroFilme(filmes, atores, diretores);
        } else if(menu == -1){
            break;
        } else {
            cerr << "Número inválido!" << endl;
        }
    }

    atualizaDiretor(diretores);
    atualizaAtor(atores);

    return 0;
}