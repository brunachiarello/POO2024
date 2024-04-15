#include <iostream>

using namespace std;

int main(){
    
    int numeros[10] = {1, 2, 3 , 4, 5, 6, 7, 8, 9, 10};
    int *pnum = numeros;

    cout << "*(numeros+4): " <<*(numeros+4) << endl;
    cout << "pnum+4: " << pnum+4 << endl;
    cout << "pnum[4]: " << pnum[4] << endl;
    cout << "*(pnum+4): " << *(pnum+4) << endl;
    cout << "numeros[4]: " << numeros[4] << endl;

    return 0;
}