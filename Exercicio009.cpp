#include <iostream>
#include <climits>

using namespace std;

void calcula_matriz(int matriz[6][4]){
     
    int resulta[6][4] = {0}; // Armazenar resultados
    
    for(int l = 0; l < 6; l++){
        int maior = INT_MIN; // Valor maior troca em cada linha
        for(int c = 0; c < 4; c++){ // Lê e pega o maior
            if(matriz[l][c] > maior){
                maior = matriz[l][c];
            }
        } 
        for(int c = 0; c < 4; c++){  // Multiplica pelo maior
            resulta[l][c] = matriz[l][c] * maior;   
        }
    }

    for (int l = 0; l < 6; l++) { // Imprime resultado
        for (int c = 0; c < 4; c++) {
            cout << resulta[l][c] << " ";
        }
        cout << endl;
    }
}

int main(){
    int matriz[6][4];

    for(int l = 0; l < 6; l++){ // l = linha
        for(int c = 0; c < 4; c++){ // c = coluna
            cin >> matriz[l][c];
        }
    }
    
    calcula_matriz(matriz);
    
    return 0;
}