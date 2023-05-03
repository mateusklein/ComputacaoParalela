#include <stdio.h>
#include <stdlib.h>
# include <omp.h>
#include <time.h>

#define NUM_THREADS 10;

int main(void){
  int num = 100;
  int i=0;
  int lista[num]; 
  int n_proc = rand()%100;   
  int index_proc = -1;
  srand(time(NULL));
  do{
    lista[i] = rand()%100;
    int igual = 0; 
    for(int j=0; j<i; j++){ 
      if(lista[j] == lista[i]){
        igual = 1;
      }
    }
    if(igual == 0){ 
      i++;
    }
  }while(i<num);
    
  #pragma omp paralel num_threads(NUM_THREADS){
      int fim = num *  omp_get_thread_num();
        int ini = fim - (num / omp_get_num_threads());
        for(int i=ini; i<fim; i++){
                #pragma omp critical{
                        if(lista[i]==n_proc){
                                index_proc = i;
                        }
                }
        }
  }
  printf("Index do elemento procurado: %d", index_proc);
}
