#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &n);

    int matriz[m][n], transposta[n][m];

    printf("Digite os elementos da matriz:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz original:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Gerando a transposta da matriz
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }

    printf("Matriz transposta:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
