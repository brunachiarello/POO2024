#include <iostream>

using namespace std;

struct Data{
    int dia, mes, ano;
};


bool anoBissexto(Data data){
    if (data.ano % 400 == 0){
        return true;
    } else if ((data.ano % 4 == 0) && (data.ano % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}


void dataValida(Data data[5]){
    int dataInvalida = 0;

    for (int i = 0; i < 5; i++){
        if (data[i].dia >= 1 && data[i].dia <= 31 && data[i].mes >= 1 && data[i].mes <= 12){ // mes e dia válido 

            if (data[i].mes == 2){ // mes é fevereiro

                if (anoBissexto(data[i]) == true){ // ano é bissexto
                    if (data[i].dia == 29){
                        cout << "+" << endl;
                    } else {
                        cout << "-" << endl;
                        dataInvalida++;
                    }

                } else { // ano não é bissexto
                    if (data[i].dia <= 28){
                        cout << "+" << endl;
                    } else {
                        cout << "-" << endl;
                        dataInvalida++;
                    }
                }

            } else { // mes não é fevereiro
                if ((data[i].mes == 4) || (data[i].mes == 6) || (data[i].mes == 9) || (data[i].mes == 11)){ // mes de 30 dias
                        if (data[i].dia <= 30){ 
                            cout << "+" << endl;
                        } else {
                            cout << "-" << endl;
                            dataInvalida++;
                        }

                } else if ((data[i].mes == 1) || (data[i].mes == 3) || (data[i].mes == 5) || (data[i].mes == 7) || // mes de 31 dias
                            (data[i].mes == 8) || (data[i].mes == 10) || (data[i].mes == 12)){ 

                    if (data[i].dia <= 31){
                        cout << "+" << endl;
                    } else {
                        cout << "-" << endl;
                        dataInvalida++;
                    }
                }
            }

        } else { // mes e dia inválido
            cout << "-" << endl;
            dataInvalida++;
        }
    }

    if (dataInvalida == 5){ // 5 datas inválidas
         cout << "*" << endl;
    }
}

int main(){
    Data data[5];

    // Lê 5 datas
    for(int i = 0; i < 5; i++){
        cin >> data[i].dia >> data[i].mes >> data[i].ano;
    }

    dataValida(data);

    return 0;
}