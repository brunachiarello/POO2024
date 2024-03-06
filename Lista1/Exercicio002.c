#include <stdio.h>
#include <limits.h>

int conta_inteiros(FILE *input);

int conta_inteiros(FILE *input) {
  int tam;
  int num[];
  for(int i = 0; i < tam; i++){
    fscanf(input, "%d", &num[tam]);
    return num;
  }
}

int main() {
  printf("%d\n",conta_inteiros(stdin));
  return 0;
}
