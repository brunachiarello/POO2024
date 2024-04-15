#include <iostream>
#include <sstream>
#include "Pessoa.hpp"

class ListaEncadeada {
private:

  class Nodo {
  public:
    Pessoa pessoa;
    Nodo *prox;
    Nodo(Pessoa &p) {
      pessoa = p;
      prox = nullptr;
    }
  };

  Nodo *inicio, *fim;

public:
  ListaEncadeada() {
    inicio = fim = nullptr;
  }
  
  bool estaVazia() { return inicio == nullptr; }
  
  void insereNoInicio(Pessoa &p) {
    Nodo *novo = new Nodo(p);
    if ( inicio == nullptr )
       inicio = fim = novo;
    else {
       novo->prox = inicio;
       inicio = novo;
    }
  }
  
  void insereNoFim(Pessoa &p) {
    Nodo *novo = new Nodo(p);
    if ( fim == nullptr )
       inicio = fim = novo;
    else {
       fim->prox = novo;
       fim = novo;
    }
  }

  Pessoa *retornaUltimo(){ // Retorna um apontador para o último elemento da lista. Caso a lista esteja vazia, o método deve devolver nullptr.
    if (inicio == nullptr){
      return nullptr;
    }
    Nodo *atual = inicio;
    while(atual->prox != nullptr){
      atual = atual->prox;
    }
    return atual;
  }

  Pessoa *buscaPessoa(string nome){
    Nodo *atual = inicio;
    while (atual != nullptr){
      if (atual->nome == nome){
        return atual;
      }
      atual = atual->prox;
   }
   return nullptr;
  }
  
  string str() {
    stringstream ss;
    Nodo *aux = inicio;
    while ( aux != nullptr ) {
       cout << aux->pessoa.str() << endl;
       aux = aux->prox;
    }
    return ss.str();
  }
  
};

int main() {
  ListaEncadeada lista;
  if ( lista.estaVazia() ) cout << "> Lista vazia..." << endl;
  
  Pessoa a("A","a"), b("B","b"), c("C","c");
  lista.insereNoInicio( c );
  lista.insereNoInicio( b );
  lista.insereNoInicio( a );
  cout << lista.str() << endl;
  
  Pessoa d("D", "d"), e("E", "e"), f("F", "f");
  lista.insereNoFim( d );
  lista.insereNoFim( e );
  lista.insereNoFim( f );
  cout << lista.str() << endl;
  
  return 0;
}

