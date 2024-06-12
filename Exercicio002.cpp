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
    Filme(int n=-1, string t="", int f=-1, string e="");
    ~Filme();
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
    return 0;
}