#include <iostream>

using namespace std;

double calcula_media(int idade[10]){ // media das idades das dez pessoas
    double soma; 
    for(int i = 0; i < 10; i++){
        if(i < 10){
           soma = idade[i] + idade[i + 1]; 
        }
    }
    return soma/10;
}

int calcula_quant(double peso[10], double altura[10]){ // quantidade de pessoas com peso superior a 90 kg e altura inferior a 1,50 metro
    int quant = 0;
    for(int i = 0; i < 10; i++){
        if(peso[i] > 90.0 && altura[i] > 1,5){
            quant++;
        }
    }
    return quant;
}

double calcula_pcent(int idade[10], double altura[10]){ // porcentagem de pessoas com idade entre 10 e 30 anos entre as pessoas que medem mais de 1,90m
    double total; 
    for(int i = 0; i < 10; i++){
        if(idade[i] > 1,9 && idade[i] >= 10 && idade[i] <= 30){
            total++;
        }
    }
    return total/100;
}

int main(){
    int idade[10];
    double peso[10];
    double altura[10];

    for(int i = 0; i < 10; i++){
        cin >> idade[i] >> peso[i] >> altura[i];
    }

    cout << calcula_media(idade) << " " << calcula_quant(peso, altura) << " " << calcula_pcent(idade, altura);
    return 0;
}