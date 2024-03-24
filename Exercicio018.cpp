#include <iostream>

using namespace std;

/*
x aumenta para a direita e diminui para a esquerda

y aumenta para cima e diminui para baixo

orientacao:
    0 = virado para direita
    1 = virado para cima
    2 = virado para a esquerda
    3 = virado para baixo
*/

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
        posicaoX++;
    }

    void giraEsquerda(){
        orientacao = 2;
        posicaoX--;
    }

    void avanca(){
        if(orientacao == 0){
            posicaoX++;

        } else if(orientacao == 1){
            posicaoY++;

        } else if(orientacao == 2){
            posicaoX--;

        } else if(orientacao == 3){
            posicaoY--;
        }
    }

    void posiciona(int x, int y, int ori){
        posicaoX = x;
        posicaoY = y;
        orientacao = ori;
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
        for(int i = 0; i < operacao.length(); i++){
            if(operacao[i] == 'D'){
                giraDireita();

            } else if(operacao[i] == 'E'){
                giraEsquerda();

            } else if(operacao[i] == 'A'){
                avanca();
            } 
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
