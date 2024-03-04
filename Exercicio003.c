#include <stdio.h>

struct data {
  int dia, mes, ano;
};

int compara_datas(struct data d1, struct data d2);

int compara_datas(struct data d1, struct data d2) {
  if(d1.dia && d1.mes && d1.ano == d2.dia && d2.mes && d2.ano){
    return 0;
  }
  else if(d1.dia && d1.mes && d1.ano < d2.dia && d2.mes && d2.ano){
    return -1;
  }
  
  else if(d1.dia && d1.mes && d1.ano > d2.dia && d2.mes && d2.ano){
    return 1;
  }
}

// 20 1 1980 21 3 1979
// 20 1 1979 21 3 1980
//  5 8 2022 5 8 2022

int main() {
  struct data d1, d2;
  scanf("%d %d %d",&d1.dia, &d1.mes, &d1.ano);
  scanf("%d %d %d",&d2.dia, &d2.mes, &d2.ano);
  printf("%d\n",compara_datas(d1,d2));
  return 0;
}
