#include <iostream>

using namespace std;

struct Data{
    int dia, mes, ano;
};


bool dataValida(const Data &data){
// mes 30 válido
    if(data.mes == 2 && data.dia > 28 && data.ano % 4 != 0 ){ // se o mês for 2 e o dia for maior que 28 sem ser ano bissexto retorna false
        return false;
    } else if(data.mes == 2 && data.dia > 28 && data.ano % 4 == 0 ) { // se o mês for 2 e o dia for maior que 28 e ano bissexto retorna false
        return true;
    } else if(data.dia > 30 && (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)){ // se dia for maior que 30 e mês não é de 30 retorna false
        return false;
    } 
// mes 31 valido
// dia valido
    return false;
}


int main(){
    Data data[5];

    // Lê 5 datas
    for(int i = 0; i < 5; i++){
        cin >> data[i].dia >> data[i].mes >> data[i].ano;
            
    }

    for(int i = 0; i < 5; i++){
    if(dataValida(*data) == true){
        cout << "+" << endl;
    } else if(dataValida(*data) == false){
        cout << "-" << endl;
    } else {
        cout << "*" << endl;
    }
    }

    return 0;
}