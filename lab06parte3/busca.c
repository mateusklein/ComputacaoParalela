#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 10

int main(){
  srand(time(NULL));
  int num = 10;
  int i=0;
  int lista[num]; 
  int n_proc = rand()%num;  
  printf("num procurado: %d \n", n_proc); 
  int index_proc = -1;
  do{
    lista[i] = rand()%num;
    int igual = 0; 
    for(int j=0; j<i; j++){ 
      if(lista[j] == lista[i]){
        igual = 1;
      }
    }
    if(igual == 0){
      printf("vetor %d: %d \n", i, lista[i]); 
      i++;
    }
  }while(i<num);
    
  #pragma omp parallel num_threads(NUM_THREADS)
  {
      printf("entrou na thread %d \n", omp_get_thread_num());
      int t = omp_get_thread_num();
      int num_t = omp_get_num_threads();
      int intervalo = num/num_t;
      int ini = t * intervalo;
      int fim = ini + intervalo;
      for(int j=ini; j<fim; j++){
      	 if(lista[j]==n_proc){
		 #pragma omp critical
		 {
			 if(index_proc == -1){
           		    index_proc = j;
			 }
		 }
           }
       }
  }
  printf("Index do elemento procurado: %d \n", index_proc);
}
