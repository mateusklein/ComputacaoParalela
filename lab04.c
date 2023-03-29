#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid, i, j, k, **a, **b, **c;
    key_t key = IPC_PRIVATE;

    // Aloca memória compartilhada para as matrizes
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    a = (int **) shmat(shmid, NULL, 0);

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    b = (int **) shmat(shmid, NULL, 0);

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    c = (int **) shmat(shmid, NULL, 0);

    // Define valores para as matrizes
    for (i = 0; i < 3; i++) {
        a[i] = (int *) shmat(shmid, NULL, 0);
        b[i] = (int *) shmat(shmid, NULL, 0);
        c[i] = (int *) shmat(shmid, NULL, 0);

        for (j = 0; j < 3; j++) {
            a[i][j] = i * 3 + j;
            b[i][j] = i * 3 + j;
            c[i][j] = 0;
        }
    }

    // Multiplica as matrizes
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Imprime o resultado
    printf("Resultado:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Libera a memória compartilhada
    shmdt(a);
    shmdt(b);
    shmdt(c);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
