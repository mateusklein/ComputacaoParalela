#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void *Pth_trap(void *rank);
double f(double x){
	return exp(x);
}

//inicio do intervalo
double ini = 1;
//final do intervalo
double fin = 9;
//variavel para guardar o valor total
double total = 0;

int main(){
  double args[10];
  args[0] = ini;
  double h = (fin-ini)/2;
  double cont = ini + h;
  int num=1;
  while(cont<=fin){
    args[num] = cont;
    cont += h;
    num++;
  }
  pthread_t threads[num];
  
  for (int thread_id = 0; thread_id < num; thread_id++) {
    pthread_create(&threads[thread_id], NULL, Pth_trap, &args[thread_id]);
  }

  for (int thread_id = 0; thread_id < num; thread_id++) {
    pthread_join(threads[thread_id], NULL);
  }

  printf("resultado para o intervalo [%f,%f] é: %f \n", ini, fin, total);

  return 0;
}

void *Pth_trap(void *rank) {
  double *i = rank;
  if(*i==ini){
    total = (total + f(*i));
  }
  else if(*i==fin){
    int div = ((fin - ini) /2) /2;
    total = total + f(*i);
    total = div * total;
  }
  else{
    total = (total + (2 * f(*i)));
  }
  return NULL;
} 
