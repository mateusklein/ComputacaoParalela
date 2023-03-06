//Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros. Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos os números lidos.

#include <stdio.h>

int main(void) {

  int tamanho = 3, i, j, menor=1000000, menorlinha=0;

  int matriz[3][3] = {1, 15, 23, 
                      53, 42, 86, 
                      2, 18, 19};
  for (i = 0; i < tamanho; i++) {
    for (j = 0; j < tamanho; j++) {
      if (matriz[i][j] < menor) {
        menor = matriz[i][j];
        menorlinha = i;
      }
    }
  }
  for (i = 0; i < tamanho; i++)
  {
    printf("\n");
      for (j = 0; j < tamanho; j++)
        printf("%d ", matriz[i][j]);
    }
  printf("\nDada a matriz acima o menor número está na linha %d\n", menorlinha);

  return 0;
}