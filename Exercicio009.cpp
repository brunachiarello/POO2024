#include <iostream>
#include <climits>

using namespace std;

int imprime(int matriz[6][4]){
    for(int l = 0; l < 6; l++){ 
        for(int c = 0; c < 4; c++){ 
            cout << matriz[l][c] << endl;
        }
    } return 1;
}

int calcula_matriz(int matriz[6][4]){
    int maior = INT_MIN; 
    for(int l = 0; l < 6; l++){
        for(int c = 0; c < 4; c++){
            if(c < maior){
                maior = c;
                matriz[l][c] = matriz[l][c] * maior;
                
            }
        } 
    }
    return imprime(matriz);
}



int main(){
    int matriz[6][4];

    for(int l = 0; l < 6; l++){ // l = linha
        for(int c = 0; c < 4; c++){ // c = coluna
            //cout << "Lendo matriz..." << endl;
            cin >> matriz[l][c];
        }
    }

    calcula_matriz(matriz);
    
    return 0;
}