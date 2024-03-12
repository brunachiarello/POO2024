#include <iostream>

using namespace std;
/*Fac ¸a um programa em C++ que leia um vetor com nove n´ umeros inteiros, calcule e mostre os n´ umeros primos e
 suas respectivas posic ¸˜ oes.*/

void primo(int vetor[9]){
    for(int i = 0; i < 9; i++){
        int j;
        for (j = 2; j * j <= vetor[i]; j++) {
            if (vetor[i] % j == 0){
                break;
            }
        
        }
        if (j * j > vetor[i]) {
            cout << vetor[i] << i << endl;
        }
    }

}
   
int main(){
    int vetor[9];
    for(int i = 0; i < 9; i++){
        cin >> vetor[i];
    }

    primo(vetor);

    return 0;
}