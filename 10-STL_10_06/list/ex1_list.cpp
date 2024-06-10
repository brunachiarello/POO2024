#include <iostream>
#include <list>

using namespace std;

void mostraLista(string nome, list<int> l)
{
    cout << nome << " = { ";
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        if (it != l.begin())
            cout << ',';
        cout << *it;
    }
    cout << " }" << endl;
}
int main()
{
    // lista de 4 inteiros com valor 100
    list<int> first(4, 100);
    mostraLista(" first ", first);
    // lista criada a partir de outra
    list<int> second(first.begin(), first.end());
    mostraLista(" second ", second);
    // lista criada com construtor de copia
    list<int> third(second);
    mostraLista(" third ", third);
    // a lista pode ser criada a partir de um array
    int v[] = {2, 3, 5, 7, 11};
    list<int> fourth(v, v + sizeof(v) / sizeof(int));
    mostraLista(" fourth ", fourth);
    list<int> fifth; // lista de inteiros vazia
    mostraLista(" fifth ", fifth);
    fifth.push_front(1); // insere na frente
    mostraLista(" fifth ", fifth);
    fifth.push_front(2);
    mostraLista(" fifth ", fifth);
    fifth.push_front(3);
    mostraLista(" fifth ", fifth);
    fifth.push_back(4); // insere no final
    mostraLista(" fifth ", fifth);
    fifth.push_back(1);
    mostraLista(" fifth ", fifth);
    fifth.sort(); // ordena a lista
    mostraLista(" fifth ", fifth);
    fifth.remove(4); // remove todos os 4s
    mostraLista(" fifth ", fifth);
    fifth.unique(); // remove elementos duplicados
    mostraLista(" fifth ", fifth);
    fifth.pop_front(); // remove elemento do inicio
    mostraLista(" fifth ", fifth);
    fifth.pop_back(); // remove elemento do fim
    mostraLista(" fifth ", fifth);
    fifth.clear(); // esvazia a lista
    mostraLista(" fifth ", fifth);
    return 0;
}