#include <stdio.h>
#include <stdlib.h>
#include <openacc.h>

#define SIZE 3

int main() {
    int matrix[SIZE][SIZE];
    int vector[SIZE];
    int result[SIZE];
    int cont = 1;

    // Inicializando a matriz e o vetor com valores de exemplo
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = cont;
            cont++;
        }
        vector[i] = i+1;
    }

    #pragma acc kernels
    for (int i = 0; i < SIZE; i++) {
        int sum = 0;
        #pragma acc loop reduction(+:sum)
        for (int j = 0; j < SIZE; j++) {
            sum += matrix[i][j] * vector[j];
        }
        result[i] = sum;
    }

    // Imprimindo o resultado
    printf("Resultado:\n");
    printf("[ ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("]\n");

    return 0;
}
