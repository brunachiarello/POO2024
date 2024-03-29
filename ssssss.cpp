#include <iostream>
using namespace std;

// Definição da estrutura para armazenar datas
struct Data {
    int dia;
    int mes;
    int ano;
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

// Função para verificar se uma data é válida
bool dataValida(const Data& data) {
    for(int i = 0; i < 5; i++){
        // basicos
        if(*data[i].dia < 0 || data[i].dia > 31){ // dia menor que 0 ou maior que 31
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

// Função para comparar duas datas
bool comparaDatas(const Data& data1, const Data& data2) {
    // Implemente aqui a lógica para comparar as datas
    // Retorne true se data1 for anterior a data2, caso contrário, retorne false.
    return true; // Substitua isso pela sua lógica real
}

int main() {
    Data datas[5]; // Array para armazenar as 5 datas

    // Ler as 5 datas
    for (int i = 0; i < 5; ++i) {
        cout << "Digite a data " << i + 1 << " (dia mês ano): ";
        cin >> datas[i].dia >> datas[i].mes >> datas[i].ano;

        // Verificar se a data é válida e mostrar a mensagem correspondente
        if (dataValida(datas[i])) {
            cout << "+"; // Data válida
        } else {
            cout << "-"; // Data inválida
        }
    }

    // Encontrar a data mais antiga entre as datas válidas
    Data dataMaisAntiga = datas[0];
    bool encontrouDataValida = false;

    for (int i = 1; i < 5; ++i) {
        if (dataValida(datas[i])) {
            if (!encontrouDataValida || comparaDatas(datas[i], dataMaisAntiga)) {
                dataMaisAntiga = datas[i];
                encontrouDataValida = true;
            }
        }
    }

    // Mostrar a data mais antiga no formato "DD/MM/AAAA" ou "*"
    if (encontrouDataValida) {
        cout << "\nA data mais antiga é: " << dataMaisAntiga.dia << "/" << dataMaisAntiga.mes << "/" << dataMaisAntiga.ano << endl;
    } else {
        cout << "\nNenhuma data válida foi fornecida." << endl;
    }

    return 0;
}
