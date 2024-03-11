#include <iostream>

using namespace std;
/*Fac ¸a um programa em C++ que leia um vetor com nove n´ umeros inteiros, calcule e mostre os n´ umeros primos e
 suas respectivas posic ¸˜ oes.*/

//int primo(int vetor[9]){

    
    //return 1;

/*for(int i = 0; i < 9; i++){
       if(vetor % 0 = vetor[i]){
            cout << vetor[i] << i << endl;
        } 
    }
*/
    


int main(){
    int vetor[9];
    for(int i=0; i<9; i++){
        cin >> vetor[i];
    }

    for(int i = 1; i < 1000; i++){
        for(int j = 0; j < 9; j++){
            if(vetor[j] % i == 0){
                cout << "Não tem primos" << endl;
            } else {
                cout << vetor[j] << j << endl;
            }
        }
    }



    return 0;
}