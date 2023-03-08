#include <stdio.h>
#include <string.h>

int encontrar_caracter(char str[], char caracter) {
    int i;
    int tamanho = strlen(str);

    for (i = 0; i < tamanho; i++) {
        if (str[i] == caracter) {
            return i;
        }
    }

    return -1; // Caracter não encontrado
}

int main() {
    char str[100];
    char caracter;
    int posicao;

    printf("Digite uma string: ");
    scanf("%s", str);

    printf("Digite um caracter: ");
    scanf(" %c", &caracter);

    posicao = encontrar_caracter(str, caracter);

    if (posicao == -1) {
        printf("O caracter %c não foi encontrado na string.\n", caracter);
    } else {
        printf("O caracter %c foi encontrado na posição %d da string.\n", caracter, posicao);
    }

    return 0;
}
A função encontrar_caracter recebe como parâmetros a string str e o caracter a ser encontrado caracter. A função percorre a string procurando o caracter desejado. Se encontrar o caracter, retorna a posição na string em que ele foi encontrado. Se não encontrar, retorna -1.

No programa principal, é lida a string e o caracter a ser encontrado. A função encontrar_caracter é chamada, e o resultado é armazenado na variável posicao. Se o caracter não for encontrado, é impressa uma mensagem informando que o caracter não foi encontrado na string. Caso contrário, é impressa uma mensagem informando a posição do caracter na string.





