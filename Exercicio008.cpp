#include <iostream>

using namespace std;
/*Fac ¸a um programa em C++ que leia um vetor com nove n´ umeros inteiros, calcule e mostre os n´ umeros primos e
 suas respectivas posic ¸˜ oes.*/

void primo(int vetor[9]){

    for(int i = 0; i < 9; i++){
        for(int j = 1; j <= 1000; j++){
            if(vetor[i] % j != 0){
                
            }
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