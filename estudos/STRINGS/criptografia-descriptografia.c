#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#define TAM 81

void criptografar(char fr[]){
    for(int i = 0; fr[i] != '\0'; i++){
        char car = tolower(fr[i]);
        switch(car){
            case 'a': fr[i] = '@'; break;
            case 'e': fr[i] = '$'; break;
            case 'i': fr[i] = '&'; break;
            case 'o': fr[i] = '#'; break;
            case 'u': fr[i] = '%'; break;
        }
    }
}

void descriptografar(char fr[]) {
    for (int i = 0; fr[i] != '\0'; i++) {
        if (fr[i] == '@') fr[i] = 'a';
        else if (fr[i] == '$') fr[i] = 'e';
        else if (fr[i] == '&') fr[i] = 'i';
        else if (fr[i] == '#') fr[i] = 'o';
        else if (fr[i] == '%') fr[i] = 'u';
    }
}

void limparString(char st[]){
    int qtd = strlen(st);
    if (qtd > 0 && st[qtd-1] == '\n') {
        st[qtd-1] = '\0';
    }
}

int main(){
    char frase[TAM];
    char entradaOpcao[10];
    int opcao;
    printf("===================================================\n");
    printf("1 - Criptografar\n2 - Descriptografar\nOpção: ");
    fgets(entradaOpcao, 10, stdin);
    opcao = atoi(entradaOpcao); 
    printf("\n===================================================\n");
    printf("Digite a frase: ");
    fgets(frase, TAM, stdin);
    limparString(frase); 

    if(opcao == 1) {
        criptografar(frase);
        printf("Resultado: %s\n", frase);
        printf("\n===================================================\n");
    } else if(opcao == 2) {
        descriptografar(frase);
        printf("Resultado: %s\n", frase);
        printf("\n===================================================\n");
    } else {
        printf("Opcao invalida! Digite novamente a opção...\n");
        printf("===================================================\n");
    }

    return 0;
}

