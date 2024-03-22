#include <iostream>

using namespace std;

class Robo {
private:
    int posicaoX, posicaoY, orientacao;

public:
    Robo(){
        posicaoX = 0;
        posicaoY = 0;
        orientacao = 0;
    }

    ~Robo(){}

    void giraDireita(){
        orientacao = 0;
    }

    void giraEsquerda(){
        orientacao = 2;
    }

    void avanca(){

    }

    void posiciona(int x, int y, int orient){

    }

    int obtemPosicaoX(){
        return posicaoX;
    }
    
    int obtemPosicaoY(){
        return posicaoY;
    }

    int obtemOrientacao(){
        return orientacao;
    }

    void movimenta(string operacao){
        if(operacao == "D"){
            giraDireita();

        } else if(operacao == "E"){
            giraEsquerda();

        } else if(operacao == "A"){
            avanca();
        }
    }
};

int main() {
    int px, py, orientacao;
    string operacao;

    // LEITURA
    cin >> px;
    cin >> py;
    cin >> orientacao;
    cin >> operacao;

    // TESTE DE FUNCIONAMENTO
    Robo *robo = new Robo();
    robo->posiciona(px,py,orientacao);
    if ( robo->obtemPosicaoX()!=px || robo->obtemPosicaoY()!=py ||
    robo->obtemOrientacao()!=orientacao )
    return 1;

    // OPERACAO
    robo->movimenta(operacao);
    
    // SAIDA
    cout << robo->obtemPosicaoX() << " ";
    cout << robo->obtemPosicaoY() << " ";
    cout << robo->obtemOrientacao() << endl;
    delete robo;
    return 0;
}
