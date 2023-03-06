//Crie uma função capaz de multiplicar uma linha de uma matriz por um dado número. Faça o mesmo para uma coluna.

#include <stdio.h>

int main(void) {

  int lin, col, multiplicador; 
  int matriz[3][3] = {1, 15, 23, 
                      53, 42, 86, 
                      2, 18, 19};

    for (lin = 0; lin < 3; lin++)
    {
        printf("\n");
        for (col = 0; col < 3; col++)
            printf("%d ", matriz[lin][col]);
    }
    printf("\n\nDada a matriz acima, digite um numero para multiplicar uma linha e uma coluna da matriz: \n");
    scanf("%d", &multiplicador);

    for (int i = 0; i < 3; i++){
      //multiplicando a 2 linha 
      if(i == 2){
        for (int j = 0; j < 3; j++){
        matriz[i][j] = matriz[i][j]*multiplicador;}
      }
      
      for (int j = 0; j < 3; j++){
        //multiplicando a 2 coluna
        if(j == 2){
        matriz[i][j] = matriz[i][j]*multiplicador;
        }
      }
    }
  
   //print matriz multiplicada
    printf("\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        } printf("\n");
    }
  
return 0;
}