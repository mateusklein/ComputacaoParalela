//Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct. O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas. A struct deve armazenar os dados de idade, peso e altura

#include <stdio.h>


  typedef struct 
{
    char Nome[10];
    float Peso;  
    int Idade;   
    float Altura;
} Pessoa; 

int main(void) {
  
  Pessoa* pessoa = malloc (3 * sizeof(Pessoa));

  strncpy(pessoa[0].Nome, "PALOMA", 10);
  pessoa[0].Peso = 70;  
  pessoa[0].Idade = 24;
  pessoa[0].Altura = 1.75;

  strncpy(pessoa[1].Nome, "ARTHUR", 10);
  pessoa[1].Peso = 55;  
  pessoa[1].Idade = 19;
  pessoa[1].Altura = 1.95;

  strncpy(pessoa[2].Nome, "PEDRO", 10);
  pessoa[2].Peso = 90;  
  pessoa[2].Idade = 15;
  pessoa[2].Altura = 1.35;

  for(int i=0; i<3; i++) {
    printf(" %s tem %d anos, pesa %.2lf kg e tem %.2f cm de altura\n",pessoa[i].Nome, pessoa[i].Idade,pessoa[i].Peso,pessoa[i].Altura);
  }

  free(pessoa);
  return 0;
}