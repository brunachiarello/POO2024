#include <iostream>
#include "Filme.cpp"

using namespace std;

class Artista {
protected:
    string nomeArtista;
    Filmes participacao;
public:
    Artistas(){}
    ~Artistas(){}
    void defineNomeArtista(string nA){
        nomeArtista = nA;
    }
    string obtemNomeArtista(){
        return nomeArtista;
    }
};