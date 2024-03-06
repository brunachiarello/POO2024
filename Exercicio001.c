#include <stdio.h>

#define MAX 100

void processa_vetor(int *vet, int tam, int val);

void processa_vetor(int *vet, int tam, int val) {
/* Recebe um vetor de inteiros, seu tamanho, um valor val e troca todas as ocorrencias de val no vetor por val+1,
exceto a ultima ocorrencia */
  for(int i = tam - 1; i >= 0; i--){
    do {
      vet[i] = val + 1;
    } while ((vet[i] == val));
      //if(vet[i] == val){
      
       // vet[i] = val + 1;
    
     // }
  }
}

int main() {
  int i, tam, val, vet[MAX];
  scanf("%d",&tam);

  if ( tam < 1 || tam > MAX ) return 1;
  for (i=0; i<tam; ++i)
      scanf("%d",&vet[i]);	

  scanf("%d",&val);
  processa_vetor(vet,tam,val);
  printf("%d",vet[0]);

  for (i=1; i<tam; ++i)
      printf(" %d",vet[i]);

  printf("\n");
  return 0;
}
