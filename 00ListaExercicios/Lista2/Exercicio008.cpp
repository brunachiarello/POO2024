#include <iostream>

using namespace std;

int primo(int n){ // verifica se é primo
    if(n <= 1){
        return 0;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void imprime(int vetor[9]){
    for(int i = 0; i < 9; i++){
        if(primo(vetor[i])) { // se for primo imprime
            cout << vetor[i] << " " << i << endl;
        }
    }
}

int main() {
    int vetor[9];
    for(int i = 0; i < 9; i++){
        cin >> vetor[i];
    }

    imprime(vetor);

    return 0;
}