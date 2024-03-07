#include <stdio.h>
#include <limits.h>

int conta_inteiros(FILE *input);

int conta_inteiros(FILE *input) {
  char *num;
  fscanf(stdin, num);
  //for(int i = 0; i < input; i++){
    int *maior = 0;
    if(maior < num){
      maior = num;
    }
    printf("%p", maior);
  //}
}

int main() {
  printf("%d\n",conta_inteiros(stdin));
  return 0;
}
