#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 10

int main(int argc, char* argv[]){
  int lista[100000];
  FILE *arq;
  char Linha[100];
  char *result;
  int i;
  arq = fopen("vetor1.txt", "rt");
  if (arq == NULL) {
     printf("Problemas na abertura do arquivo\n");
  }
  i = 1;
  while (!feof(arq)){
      result = fgets(Linha, 100, arq);
      if (result)
	  lista[i] = strtol(Linha, NULL, 10);
      i++;
  }
  fclose(arq);  


  srand(time(NULL));
  int num = i;
  i=0;
  int n_proc = strtol(argv[1], NULL, 10);
  int index_proc = -1;
    
  #pragma omp parallel num_threads(NUM_THREADS)
  {
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
