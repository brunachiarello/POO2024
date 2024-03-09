#include <stdio.h>
#include <limits.h>

int conta_inteiros(FILE *input);

int conta_inteiros(FILE *input) {
  int num;
  int maior = INT_MIN;
  
  while(fscanf(input, "%d", &num) == 1){
    if(num > maior){
      maior = num;
    }   
  }
  return maior; 
}

int main() {
  printf("%d\n",conta_inteiros(stdin));
  return 0;
}
