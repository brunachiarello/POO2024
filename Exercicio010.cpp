#include <iostream>

using namespace std;

struct Data{
    int dia, mes, ano;
};

bool meses30(Data data[5]){
    int mes30[4] = {4, 6, 9, 11};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            if(data[i].mes == mes30[j]){ // se o mes for um de 30, retorna true
                return true;
            }
        }
    }
    return false;
}

bool meses31(Data data[5]){
    int mes31[7] = {1, 3, 5, 7, 8, 10, 12};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            if(data[i].mes == mes31[j]){ // se o mes for um de 31, retorna true
                return true;
            }
        }
    }
    return false;
}

bool mesesFev(Data data[5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 2; j++){
            if(data[i].mes == 2){ // se o mes for fevereiro(2), retorna true
                return true;
            }
        }
    }
    return false;
}

bool anoBi(Data data[5]){
    for(int i = 0; i < 5; i++){
        if(data[i].ano % 4 == 0){ // se ano é bissexto, retorna true
            return true;
        }
    }
    return false;
}

bool dataValida(Data data[5]){
    for(int i = 0; i < 5; i++){
        // basicos
        if(data[i].dia < 0 || data[i].dia > 31){ // dia menor que 0 ou maior que 31
            return false;
        } 
        
        else if(data[i].mes > 12 || data[i].mes < 1){ // mes maior que 12 ou menor que 1
            return false;
        }

        // casos especiais
        else if(meses30(data) == true){ // mes de 30 dias
            if(data[i].dia != 30){
                return false;
            } else {
                return true;
            }
        }

        else if(meses31(data) == true){ // mes de 31 dias
            if(data[i].dia != 31){
                return false;
            } else {
                return true;
            }
        }

        else if(mesesFev(data) == true){ // mes é fevereiro
            if(anoBi(data) == true && data[i].dia == 29){ // é bissexto ent tem 29 dias
                return true;
            } else if(data[i].dia == 28){
                return true;
            } else {
                return false;
            }

        }
    }  
    return false;  
}

int main(){
    Data data[5];

    // Lê 5 datas
    for(int i = 0; i < 5; i++){
        cin >> data[i].dia >> data[i].mes >> data[i].ano;
            
    }

    for(int i = 0; i < 5; i++){
    if(dataValida(data) == true){
        cout << "+" << endl;
    } else if(dataValida(data) == false){
        cout << "-" << endl;
    } else {
        cout << "*" << endl;
    }
    }

    return 0;
}