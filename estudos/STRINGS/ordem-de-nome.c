/******************************************************************************
 * DESCRIÇÃO: 
 * Programa de ordenação de nomes em ordem alfabética (A-Z).
 * 
 * FUNCIONAMENTO:
 * 1. Entrada: O usuário define a quantidade de nomes e digita cada um deles.
 * 2. Processamento: O programa percorre a lista comparando os nomes par a par.
 * 3. Troca: Se um nome vem depois do outro alfabeticamente, eles trocam de lugar.
 * 4. Saída: Exibe a lista completa devidamente organizada no console.
 * 
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Algoritmo de Ordenação: Implementação do método Bubble Sort.
 * - Biblioteca <string.h>: Uso de strcmp() para comparar e strcpy() para copiar strings.
 * - Matriz de Caracteres: Manipulação de listas de strings (char lista[][50]).
 * - Alocação Estática/Dinâmica: Uso de variável 'n' para definir o tamanho da matriz.
 * - Procedimentos: Divisão modular entre as funções de ordenar e exibir.
 * 
 * Autor: Amanda Aziz
 * Data: 23 de Abril de 2026
 *******************************************************************************/


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
