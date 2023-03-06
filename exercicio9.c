#include <stdio.h>

int main(void) {
    int linhas;
    int colunas;
    int valor;
    printf("Numero de linhas:\n");
    scanf("%d", &linhas);
    printf("Numero de colunas:\n");
    scanf("%d", &colunas);
    int matriz[linhas][colunas];
    for(int i=1; i<=linhas;i++){
        for(int j=1; j<=colunas; j++){
            printf("DIGITE VALOR ELEMENTO %d x %d: \n", i, j);
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }
    for(int i=1; i<=linhas;i++){
        for(int j=1; j<=colunas; j++){
            if(matriz[i][j]<0){
                matriz[i][j] = matriz[i][j] * -1;
                printf("ELEMENTO %d x %d: %d \n", i, j, matriz[i][j]);
            }
            else{
                printf("ELEMENTO %d x %d: %d \n", i, j, matriz[i][j]);
            }
        }
    }
}
