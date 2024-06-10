#include <iostream>
#include <deque>

using namespace std;

void mostraDeque(string nome, deque<int> l)
{
    cout << nome << " = { ";
    deque<int>::iterator it;
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
    // deque de 4 inteiros com valor 100
    deque<int> first(4, 100);
    mostraDeque(" first ", first);
    // deque criado a partir de outro
    deque<int> second(first.begin(), first.end());
    mostraDeque(" second ", second);
    // deque criado com construtor de copia
    deque<int> third(second);
    mostraDeque(" third ", third);
    // o deque pode ser criado a partir de um array
    int v[] = {2, 3, 5, 7, 11};
    deque<int> fourth(v, v + sizeof(v) / sizeof(int));
    mostraDeque(" fourth ", fourth);
    // deque de inteiros vazio
    deque<int> fifth;
    mostraDeque(" fifth ", fifth);
    fifth.push_front(1); // insere na frente
    mostraDeque(" fifth ", fifth);
    fifth.push_front(2);
    mostraDeque(" fifth ", fifth);
    fifth.push_front(3);
    mostraDeque(" fifth ", fifth);
    fifth.push_back(4); // insere no final
    mostraDeque(" fifth ", fifth);
    fifth.push_back(1);
    mostraDeque(" fifth ", fifth);
    fifth.pop_front(); // remove elemento do inicio
    mostraDeque(" fifth ", fifth);
    fifth.pop_back(); // remove elemento do fim
    mostraDeque(" fifth ", fifth);
    fifth.clear(); // esvazia o Deque
    mostraDeque(" fifth ", fifth);
    return 0;
}