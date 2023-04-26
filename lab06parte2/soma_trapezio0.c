#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void *Pth_trap(void *rank);
double f(double x){
	return exp(x);
}

//inicio do intervalo
double ini = 2;
//final do intervalo
double fin = 2.6;
//variavel que define o numero de intervalos + um (respectivamente o numero de threads)
int n_int = 6;
//variavel para guardar o valor total
double total = 0;

int main(){
  double args[n_int+1];
  double h = (fin-ini)/n_int;
  double cont = ini;
  int num=0;
  while(cont<fin){
    args[num] = cont;
    cont += h;
    num++;
  }
  args[num] = fin;
  pthread_t threads[n_int+1];
  
  for (int thread_id = 0; thread_id <= num; thread_id++) {
    pthread_create(&threads[thread_id], NULL, Pth_trap, &args[thread_id]);
  }

  for (int thread_id = 0; thread_id <= num; thread_id++) {
    pthread_join(threads[thread_id], NULL);
  }
  total = (h/2)*total;

  printf("resultado para o intervalo [%f,%f] é: %f \n", ini, fin, total);

  return 0;
}

void *Pth_trap(void *rank) {
  double *i = rank;
  if(*i==ini || *i==fin){
    total = (total + f(*i));
  }
  else{
    total = (total + (2 * f(*i)));
  }
  return NULL;
}
