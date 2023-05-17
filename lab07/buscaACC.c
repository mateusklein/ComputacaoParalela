#include <stdio.h>
#include <stdlib.h>
#include <openacc.h>
#include <time.h>
#include <string.h>

#define SIZE 1000

int main() {
  srand(time(NULL));
  int vector[SIZE];
  int element;

    
  for (int i = 0; i < SIZE; i++) {
    vector[i] = rand() % 1000;
  }
  
  element = rand() % 1000;
  int index = -1;

  #pragma acc parallel loop
  for (int i = 0; i < SIZE; i++) {
    if (vector[i] == element) {
        index = i;
      }
  }
  if (index == -1) {
    printf("Elemento não encontrado.\n");
  } else {
    printf("Elemento encontrado no índice %d.\n", index);
  }

  return 0;
}
