#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

#define NUM_THREADS 25

int mat[NUM_THREADS][NUM_THREADS];
int vec[NUM_THREADS];
int result[NUM_THREADS] = {0};

void *Pth_mat_vect(void *rank);

int main(){
  pthread_t threads[NUM_THREADS];
  int args[NUM_THREADS];

  int cont = 1;
  for(int i=0; i<NUM_THREADS; i++){
    args[i] = i;
    vec[i] = i+1;
    for(int j=0; j<NUM_THREADS; j++){
      mat[i][j] = cont;
      cont++;
    }
  } 
  
  for (int thread_id = 0; thread_id < NUM_THREADS; thread_id++) {
    pthread_create(&threads[thread_id], NULL, Pth_mat_vect, &args[thread_id]);
  }

  for (int thread_id = 0; thread_id < NUM_THREADS; thread_id++) {
    pthread_join(threads[thread_id], NULL);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    printf(" %d ", result[i]);
    printf("\n");
  }

  return 0;
}

void *Pth_mat_vect(void *rank) {
  pthread_mutex_lock(&mutex);
  int *i = rank;
  for (int j = 0; j < NUM_THREADS; j++) {
    result[*i] += mat[*i][j] * vec[j];
  }
  pthread_mutex_unlock(&mutex);
  return NULL;
}
