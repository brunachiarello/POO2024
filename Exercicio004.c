#include <stdio.h>

#define MAX 100

int tem_soma(int *vet, int tam);

int tem_soma(int *vet, int tam) {
  // Coloque a sua implementacao aqui...
}

int main() {
  int i, tam, vet[MAX];
  scanf("%d",&tam);
  if ( tam < 1 || tam > MAX ) return 1;
  for (i=0; i<tam; ++i)
      scanf("%d",&vet[i]);	
  printf("%d\n",tem_soma(vet,tam));
  return 0;
}
