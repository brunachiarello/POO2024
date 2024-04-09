// main . cpp
#include <iostream>
#include "Contador.hpp"

int main()
{
    Contador *c1 = new Contador(10);
    cout << c1->obtemValor() << endl;
    delete c1;
    return 0;
}
