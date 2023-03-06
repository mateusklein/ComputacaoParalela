//Crie uma função capaz de criar a transposta de uma matriz.

#include <stdio.h>
#define tamanho 4

void matriztransposta(int matriz[][tamanho], int matriztransposta[][tamanho])
{
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
            matriztransposta[i][j] = matriz[j][i];
}
 
int main()
{
  int matriz_transposta[tamanho][tamanho];
  int matriz[tamanho][tamanho] = { {1, 2, 3,4},{5, 6, 7, 8},{9,10,11,12},{13,14,15,16}};
    
  printf("\nMatriz inicial:\n");

  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
 
  matriztransposta(matriz, matriz_transposta);
 
  printf("\nMatriz transposta: \n");
  
  for (int i = 0; i < tamanho; i++){
    for (int j = 0; j < tamanho; j++){
      printf("%d ", matriz_transposta[i][j]);
    }
    printf("\n");
  }
 
  return 0;
}