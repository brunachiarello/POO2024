// Contador . cpp
#include <iostream>
#include "Contador.hpp"

Contador ::Contador(int v)
{ // Observar o uso de ::
    valor = v;
}
Contador ::~Contador()
{
    cout << " Destrutor de Contador chamado ..." << endl;
}
int Contador ::obtemValor()
{
    return valor;
}
void Contador ::incrementa()
{
    valor = valor + 1;
}
void Contador ::defineValor(int v)
{
    valor = v;
}
