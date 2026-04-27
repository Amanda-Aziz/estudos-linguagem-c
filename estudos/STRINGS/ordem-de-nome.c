#include <stdio.h>
#include <string.h>

void ordenarNomes(int n, char lista[][50]) {
    char aux[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(lista[i], lista[j]) > 0) {
                strcpy(aux, lista[i]);
                strcpy(lista[i], lista[j]);
                strcpy(lista[j], aux);
            }
        }
    }
}

void exibirNomes(int n, char lista[][50]) {
    printf("\n=============================================");
    printf("\nLista em ordem alfabetica:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", lista[i]);
    }
}

int main() {
    int n;
    printf("=============================================\n");
    printf("Quantos nomes voce quer digitar? ");
    scanf("%d", &n);
    char nomes[n][50];
    for (int i = 0; i < n; i++) {
        printf("Digite o nome %d: ", i + 1);
        scanf("%s", nomes[i]);
    }
    // Chamada dos procedimentos
    ordenarNomes(n, nomes);
    exibirNomes(n, nomes);

    return 0;
}
