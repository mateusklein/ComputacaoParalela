#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <string.h>

void main(){
  char comp[10];
  int num;
  printf("Digite um numero:");
  scanf("%s", &comp[0]);
  int *mem;
  int shmid;
  shmid = shmget((key_t)1122, 1024, 0666|IPC_CREAT);
  mem = (int *) shmat(shmid, NULL, 0);
  mem[0] = atoi(comp);
  pid_t id = fork();
  if(id==0){
    printf("Entrou no processo filho \n");
    //AQUI REALIZA A PRIMEIRA OPERAÇÃO
   int esc;
   int n;
   printf("Digite um numero de 1 a 4 (1-soma, 2-subt, 3-div, 4-mult)\n");
   scanf("%d", &esc);
   printf("Digite um numero: \n");
   scanf("%d", &n);
   switch(esc){
	   case 1:
		   mem[0] = mem[0] + n;
		   break;
	   case 2:
		   mem[0] = mem[0] - n;
		   break;
	   case 3:
		   mem[0] = mem[0] / n;
		   break;
	   case 4:
		   mem[0] = mem[0] * n;
		   break;
	}
    printf("Valor da variavel: %d\n", mem[0]);
  }else{
    printf("Entrou no processo pai \n");
    printf("Valor da variavel: %d\n", mem[0]);
    wait(NULL);    
    printf("Entrou no processo pai novamente\n");
    //AQUI VAI A SEGUNDA OPERAÇÃO
    
    int esc;
   int n;
   printf("Digite um numero de 1 a 4 (1-soma, 2-subt, 3-div, 4-mult)\n");
   scanf("%d", &esc);
   printf("Digite um numero: \n");
   scanf("%d", &n);
   switch(esc){
           case 1:
                   mem[0] = mem[0] + n;
		   break;
           case 2:
                   mem[0] = mem[0] - n;
		   break;
           case 3:
                   mem[0] = mem[0] / n;
		   break;
           case 4:
                   mem[0] = mem[0] * n;
		   break;
        }
	
    printf("Valor da variavel: %d \n", mem[0]);
  }
}

