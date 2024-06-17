#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Filme {
private:
    int numero;
    string titulo;
    int faixaEtaria;
    string estilo;
public:
    Filme(int n=-1, string t="", int f=-1, string e=""){
        numero = n;
        titulo = t;
        faixaEtaria = f;
        estilo = e;
    }
    ~Filme(){}
    int obtemNumero() const{ return numero; }
    string obtemTitulo() const{ return titulo; }
    int obtemFaixaEtaria() const{ return faixaEtaria; }
    string obtemEstilo() const{ return estilo; }
    
    string str() const{
        stringstream ss;
        ss << titulo << " [" << numero << "] - ";
        if(faixaEtaria == 0){
            ss << "LIVRE";
        } else {
            ss << faixaEtaria << " anos";
        }
        ss << " - " << estilo;
        return ss.str();
    }

    void defineNumero(int n){ numero = n; }
    void defineTitulo(string t){ titulo = t; }
    void defineFaixaEtaria(int f){ faixaEtaria = f; }
    void defineEstilo(string e){ estilo = e; }
    bool operator<(const Filme &f) const{ return titulo < f.titulo; }
};

vector<string> splitCSV(string linha, char separador=';') {
	vector<string> res;
	string campo = "";
	for (int i=0; i<linha.size(); ++i) {
		char c = linha.at(i);
		if (c == separador) {
			res.push_back(campo);
			campo = "";
		}
		else
			campo.append(1,c);
	}
	res.push_back(campo);
	return res;
}

int main(){
    vector<Filme> filmes;
    string linha;

    while(getline(cin,linha)){
        vector<string> campos =  splitCSV(linha, ';');
        int numero = stoi(campos[0]);
        string titulo = campos[1];
        int faixaEtaria = stoi(campos[2]);
        string estilo = campos[3];
        Filme filme(numero, titulo, faixaEtaria,estilo);
        filmes.push_back(filme);
    }

    sort(filmes.begin(),filmes.end());
        
    for(const auto &filme:filmes){
        cout << filme.str() << endl;
    }

    return 0;
}