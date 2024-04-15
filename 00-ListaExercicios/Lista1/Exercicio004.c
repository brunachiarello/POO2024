#include <stdio.h>

#define MAX 100

int tem_soma(int *vet, int tam);

int tem_soma(int *vet, int tam) {
  for(int i = 0; i < tam; i++){
    for(int j = tam - 1; j >= 0; j--){
      for(int k = tam - 2; k >= 0; k--){
        if(i != j && i != k && j != k && vet[i] == vet[j] + vet[k]){
          return 1;
        } 
      }  
    } 
  }
  return 0;
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
