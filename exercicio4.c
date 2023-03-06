//Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++

#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome1[10] = "pedro";
    char nome2[10] = "eduardo";

    for (int i = 0; i < 100; i++) {
      if (nome1[i] == nome2[i])
        continue;
      if (nome1[i] < nome2[i]) {
        printf("Em ordem alfabetica temos:\n");
        printf("%s \n", nome1);
        printf("%s \n", nome2);
      break;
    } else {
        printf("Em ordem alfabetica temos:\n");
        printf("%s \n", nome2);
        printf("%s \n", nome1);
      break;
    }
  }
  return 0;
}