#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
  pid_t id = fork();
  if(id==0){
    printf("Entrou no processo filho \n");
    //AQUI REALIZA A PRIMEIRA OPERAÇÃO
  }else{
    printf("Entrou no processo pai \n");
    wait(NULL);    
    printf("Entrou no processo pai\n");
    //AQUI VAI A SEGUNDA OPERAÇÃO
  }
}

