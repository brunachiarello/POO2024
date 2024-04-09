/*
Implemente uma classe chamada Televisor para simular o funcionamento de um aparelho
televisor. O televisor tem um controle de volume do som e um controle de seleção de canal.
Considere que:
O controle de volume permite aumentar ou diminuir a potência do volume de som em uma
unidade de cada vez.
O controle de canal também permite aumentar e diminuir o número do canal em uma
unidade, porém, também possibilita trocar para um canal indicado.
Também devem existir métodos para consultar o valor do volume de som e o canal
selecionado.
No programa principal, crie uma televisão e troque de canal algumas vezes. Aumente um
pouco o volume, e exiba o valor de ambos os atributos.
*/

#include <iostream>

using namespace std;

class Televisor {
private:
	bool ligada;
	int volume, canal;
	int volume_maximo, canal_maximo;
public:
	Televisor(int vmax=50, int cmax=100);
	void liga();
	void desliga();
	void aumentaVolume();
	void diminuiVolume();
	void aumentaCanal();
	void diminuiCanal();
	void defineCanal(int c);
	int obtemVolume();
	int obtemCanal();
	bool estaLigada();
};

Televisor::Televisor(int vmax, int cmax) {
  volume_maximo = vmax;
  canal_maximo = cmax;
  canal = 3;
  volume = vmax/2;
  ligada = false;
}

void Televisor::liga() {
  ligada = true;
}

void Televisor::desliga() {
  ligada = false;
}

void Televisor::aumentaVolume() {
  if (ligada) {
     ++volume;
     if (volume > volume_maximo) volume = volume_maximo;
  }
}

void Televisor::diminuiVolume() {
  if (ligada) {
     --volume;
     if (volume < 0) volume = 0;
  }
}

void Televisor::aumentaCanal() {
  if (ligada) {
     ++canal;
     if (canal > canal_maximo) canal = canal_maximo;
  }
}

void Televisor::diminuiCanal() {
  if (ligada) {
     --canal;
     if (canal < 1) canal = 1;
  }
}

void Televisor::defineCanal(int c) {
  if (ligada) {
     if (c >= 1 && c <= canal_maximo)
        canal = c;
  }
}

int Televisor::obtemVolume() {
  if (ligada) return volume;
  else return -1;
}

int Televisor::obtemCanal() {
  if (ligada) return canal;
  else return -1;
}

bool Televisor::estaLigada() {
  return ligada;
}

int main() {
  Televisor *tv = new Televisor(30,200);
  tv->liga();
  cout << tv->estaLigada() << " | " << tv->obtemCanal() << " | " << tv->obtemVolume() << endl;
  tv->aumentaCanal();
  tv->aumentaCanal();
  tv->aumentaCanal();
  tv->diminuiCanal();
  tv->aumentaVolume();
  tv->aumentaVolume();
  tv->aumentaVolume();
  tv->aumentaVolume();
  tv->diminuiVolume();
  cout << tv->estaLigada() << " | " << tv->obtemCanal() << " | " << tv->obtemVolume() << endl;
  tv->desliga();  
  cout << tv->estaLigada() << " | " << tv->obtemCanal() << " | " << tv->obtemVolume() << endl;
  tv->liga();  
  cout << tv->estaLigada() << " | " << tv->obtemCanal() << " | " << tv->obtemVolume() << endl;
  tv->desliga();  
  cout << tv->estaLigada() << " | " << tv->obtemCanal() << " | " << tv->obtemVolume() << endl;
  delete tv;
  return 0;  
}

