#include <stdio.h>

int aprov(int n1, int n2, int n3){
  int media = (n1+n2+n3)/3;
  int aproveitamento = (n1+n2*2+n3*3+media)/7;
  return aproveitamento;
}

int main(void) {
  int n1;
  int n2;
  int n3;
  printf("Digite a n1\n");
  scanf("%d", &n1);
  printf("Digite a n2\n");
  scanf("%d", &n2);
  printf("Digite a n3\n");
  scanf("%d", &n3);
  if(aprov(n1,n2,n3)<4){
    printf("E");
  }
  else if(aprov(n1,n2,n3)<6){
    printf("D");
  }
  else if(aprov(n1,n2,n3)<7.5){
    printf("C");
  }
  else if(aprov(n1,n2,n3)<9){
    printf("B");
  }
  else{
    printf("A");
  }
  return 0;
}
