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


    printf("Valor da variavel: %d\n", mem[0]);
  }else{
    printf("Entrou no processo pai \n");
    printf("Valor da variavel: %d\n", mem[0]);
    wait(NULL);    
    printf("Entrou no processo pai novamente\n");
    //AQUI VAI A SEGUNDA OPERAÇÃO
    

    printf("Valor da variavel: %d \n", mem[0]);
  }
}

