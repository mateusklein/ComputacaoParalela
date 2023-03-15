#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int fatorial = 1;
int num = 1;
sem_t mutex;

void *threadFunc(void *arg){
  sem_wait(&mutex);
  fatorial = (fatorial * num);
  num++;
  sem_post(&mutex);
}

int main()
{
  sem_init(&mutex, 0, 1);
  int num;
  printf ("Enter the number: ");
  scanf ("%d", &num);
  int s;
  pthread_t t[num];
  for(int i=1; i<=num; i++){
    s = pthread_create(&t[i], NULL, threadFunc, NULL);
  }
  for(int i=1; i<=num; i++){
    s = pthread_join(t[i], NULL);
  }
  printf("Fatorial de %d: %d\n", num, fatorial);
}
