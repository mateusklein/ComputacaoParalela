#include <stdio.h>

void operacao_linhas(int matriz[][n], int m, int n, int L1, int L2, int operacao) {
    int i, j, resultado;

    // Somando ou multiplicando as linhas
    for (j = 0; j < n; j++) {
        if (operacao == 1) { // Soma
            resultado = matriz[L1][j] + matriz[L2][j];
        } else if (operacao == 2) { // Multiplicação
            resultado = matriz[L1][j] * matriz[L2][j];
        }
        matriz[L2][j] = resultado;
    }
}

int main() {
    int m, n, i, j, L1, L2;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &n);

    int matriz[m][n];

    printf("Digite os elementos da matriz:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite as linhas a serem operadas (L1 L2): ");
    scanf("%d %d", &L1, &L2);

    // Operação de soma nas linhas L1 e L2
    operacao_linhas(matriz, m, n, L1, L2, 1);

    printf("Matriz com a soma das linhas L1 e L2:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Operação de multiplicação nas linhas L1 e L2
    operacao_linhas(matriz, m, n, L1, L2, 2);

    printf("Matriz com a multiplicação das linhas L1 e L2:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
