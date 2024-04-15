#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

class Clube {
private:
  string nome;
  int pontos, jogos, vitorias, empates, derrotas, gols, golsContra, saldoDeGols;
public:
  Clube(string n="", int v=0, int e=0, int d=0, int g=0, int gc=0) {
    nome = n;
    vitorias = v;
    empates = e;
    derrotas = d;
    gols = g;
    golsContra = gc;
    jogos = vitorias + empates + derrotas;
    pontos = vitorias * 3 + empates;
    saldoDeGols = gols - golsContra;
  }

  string obtemNome() const { return nome; }
  int obtemPontos() const { return pontos; }
  int obtemJogos() const { return jogos; }
  int obtemVitorias() const { return vitorias; }
  int obtemEmpates() const { return empates; }
  int obtemDerrotas() const { return derrotas; }
  int obtemGols() const { return gols; }
  int obtemGolsContra() const { return golsContra; }
  int obtemSaldoDeGols() const { return saldoDeGols; }

  string str() const {
    stringstream ss;
    ss << left << setfill(' ') << setw(20		) << nome;
    ss << right << setfill(' ') << setw(4) << pontos;
    ss << right << setfill(' ') << setw(4) << jogos;
    ss << right << setfill(' ') << setw(4) << vitorias;
    ss << right << setfill(' ') << setw(4) << empates;
    ss << right << setfill(' ') << setw(4) << derrotas;
    ss << right << setfill(' ') << setw(4) << gols;
    ss << right << setfill(' ') << setw(4) << golsContra;
    ss << right << setfill(' ') << setw(4) << saldoDeGols;
    return ss.str();
  }

  istream& le(istream& in) {
    if ( !getline(in, nome) ) return in;
    string linha;
    if ( !getline(in, linha) ) return in;   vitorias = stoi(linha);
    if ( !getline(in, linha) ) return in;   empates = stoi(linha);
    if ( !getline(in, linha) ) return in;   derrotas = stoi(linha);
    if ( !getline(in, linha) ) return in;   gols = stoi(linha);
    if ( !getline(in, linha) ) return in;   golsContra = stoi(linha);
    jogos = vitorias + empates + derrotas;
    pontos = vitorias * 3 + empates;
    saldoDeGols = gols - golsContra;
    return in;
  }
};

class CampeonatoBrasileiro {
private:
  class Nodo {
  public:
    Clube clube;
    Nodo *prox;
    Nodo(Clube &c) {
      clube = c;
      prox = nullptr;
    }
  };
  Nodo *clubes;
public:
  CampeonatoBrasileiro();
  ~CampeonatoBrasileiro();
  void adicionaClube(Clube &c);
  string clubeComMaisPontos() const;
  int pontosDe(string nome) const;
  string str() const;
};	

CampeonatoBrasileiro :: CampeonatoBrasileiro(){
  clubes = nullptr;
}

CampeonatoBrasileiro :: ~CampeonatoBrasileiro(){ // desalocar a lista
  while (clubes != nullptr){
    Nodo *atual = clubes;
    clubes = clubes->prox;
    delete atual;
  }
}

void CampeonatoBrasileiro :: adicionaClube(Clube &c){ // insere no início
  Nodo *novoClube = new Nodo(c);
  if (clubes == nullptr){
    clubes = novoClube;
  } else {
    novoClube->prox = clubes;
    clubes = novoClube;
  }
}

string CampeonatoBrasileiro :: clubeComMaisPontos() const{ // retorna obtemNome do clube
  Nodo *atual = clubes;
  string nomeClube = "";
  while (atual != nullptr){ // percorrendo a lista
    if (atual->clube.obtemPontos() > atual->prox->clube.obtemPontos()){
      nomeClube = atual->clube.obtemNome();
    } else {
      atual = atual->prox;
    }
  }
  return nomeClube;
}

int CampeonatoBrasileiro :: pontosDe(string nome) const{ // percorre alista e procura um clube, retorna os pontos dele
  Nodo *atual = clubes;
  while (atual != nullptr){ // percorrendo a lista
    if (atual->clube.obtemNome() == nome){
      return atual->clube.obtemPontos();
    } else {
      atual = atual->prox;
    }
  }
  return -1;
}

string CampeonatoBrasileiro :: str() const{
  stringstream ss;
  Nodo *atual = clubes;
  while (atual != nullptr){ // percorrendo a lista
    ss << atual->clube.str() << endl;
    atual = atual->prox;
  }
  return ss.str();
}

int main() {
  string nomeArq;
  getline(cin,nomeArq);
  ifstream in(nomeArq);
  if ( !in.is_open() ) return 1;
  CampeonatoBrasileiro cb;
  Clube c;
  while ( c.le(in) )
      cb.adicionaClube(c);
  in.close();
  cout << cb.str() << endl;
  cout << cb.clubeComMaisPontos() << endl << endl;
  cout << cb.pontosDe("Juventude") << endl;
  return 0;
}
