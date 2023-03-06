#include <stdio.h>

int main(void) {
  int num;
  printf("Digite um numero: \n");
  scanf("%d", &num);
  int num2=num;
  int i=1;
  if(num%2!=0){
    num = (num/2)+1;
  }
  while(i<=num){
    for(int j=i; j<=num2; j++){
      printf("%d ",j);
    }
    i++;
    num2--;
    printf("\n");
  }
}