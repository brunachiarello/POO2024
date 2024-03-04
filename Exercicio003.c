#include <stdio.h>

struct data {
  int dia, mes, ano;
};

int compara_datas(struct data d1, struct data d2);

int compara_datas(struct data d1, struct data d2) {
  // Coloque a sua implementacao aqui...
}

int main() {
  struct data d1, d2;
  scanf("%d %d %d",&d1.dia, &d1.mes, &d1.ano);
  scanf("%d %d %d",&d2.dia, &d2.mes, &d2.ano);
  printf("%d\n",compara_datas(d1,d2));
  return 0;
}
