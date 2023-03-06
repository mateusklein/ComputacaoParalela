//Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.


#include <stdio.h>

int removeletra(char frase[100], int indice){
    for (int i=0; i<100; i++) {
        if (i == indice) {
            for (int j = i; j < 100; j++){
                frase[j] = frase[j + 1];
            }
        }
    }
}

int main(void){
    char frase[100] = "acredito que mereco boas notas porque sou esforcada";
    int indice;

    printf("ANTES: %s", frase);
    printf("\n\nDigite o indice da letra a ser excluida. \n");
    scanf("\n%d", &indice);
    removeletra(frase, indice-1);
    printf("\nDEPOIS: %s", frase);
    return 0;
}