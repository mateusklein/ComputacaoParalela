#include <stdio.h>

int main(void) {
    char str[100];
    int resp=0;
    do{ 
        char letra;
        int pos;
        printf("QUAL LETRA DESEJA INSERIR: \n");
        scanf("%s", &letra);
        printf("QUAL POSICAO DESEJA INSERIR: \n");
        scanf("%d", &pos);
        str[pos] = letra;
        printf("DESEJA PARAR? 1-SIM 0-NAO: \n");
        scanf("%d", &resp);
    }while(resp==0);
    printf("Palavra formada: %s", str);
}