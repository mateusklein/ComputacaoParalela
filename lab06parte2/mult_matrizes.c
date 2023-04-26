#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 25

int mat[NUM_THREADS][NUM_THREADS];
int vec[NUM_THREADS];
int result[NUM_THREADS] = {0};

void Pth_mat_vect(int rank);

int main(){
  int thread_id;

  int cont = 1;
  for(int i=0; i<NUM_THREADS; i++){
    vec[i] = i+1;
    for(int j=0; j<NUM_THREADS; j++){
      mat[i][j] = cont;
      cont++;
    }
  }

  #pragma omp parallel num_threads(NUM_THREADS) private(thread_id)
  {
    thread_id = omp_get_thread_num();
    Pth_mat_vect(thread_id);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    printf(" %d ", result[i]);
    printf("\n");
  }

  return 0;
}

void Pth_mat_vect(int rank) {
  int i = rank;
  for (int j = 0; j < NUM_THREADS; j++) {
    #pragma omp atomic
    result[i] += mat[i][j] * vec[j];
  }
}
