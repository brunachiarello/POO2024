#include <iostream>
#include <climits>

using namespace std;


void calcula_matriz(int matriz[6][4]){
    int maior = INT_MIN; 
    
    for(int l = 0; l < 6; l++){
        for(int c = 0; c < 4; c++){
            if(matriz[l][c] < maior){
                maior = matriz[l][c];
                matriz[l][c] = matriz[l][c] * maior;
                
            }
        } 
    }
    
   for(int l = 0; l < 6; l++){ 
        for(int c = 0; c < 4; c++){
           cout << matriz[l][c] << " "; 
        } 
        cout << endl;
    } 
//    return 1;
}



int main(){
    int matriz[6][4];

    // Lê matriz
    for(int l = 0; l < 6; l++){ // l = linha
        for(int c = 0; c < 4; c++){ // c = coluna
            cin >> matriz[l][c];
        }
    }

    calcula_matriz(matriz);
    
    return 0;
}