/******************************************************************************
 * DESCRIÇÃO: 
 * Sistema de correção automatizada de provas com gestão de alunos e gabarito.
 * 
 * FUNCIONAMENTO:
 * 1. Cadastro: O usuário define o gabarito oficial da prova.
 * 2. Coleta: Registra nomes e respostas de cada aluno individualmente.
 * 3. Processamento: Compara cada resposta e soma os acertos.
 * 4. Saída: Gera um relatório de desempenho com status de aprovação.
 * 
 * O QUE CONTÉM NESTE CÓDIGO:
 * - Constantes: Definição de limites para Nomes (81), Questões (100) e Alunos (50).
 * - Validação de Entrada: Filtro que aceita apenas letras de 'a' até 'e'.
 * - Manipulação de Strings: Uso de fgets() e tratamento de buffer para nomes.
 * - Lógica de Avaliação: Sistema de nota de corte (mínimo de 70 acertos).
 * - Modularização: Divisão em 5 funções principais para organização da lógica.
 * 
 * Autor: Amanda Aziz
 * Data: 30 de Abril de 2026
 *******************************************************************************/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// definindo tamanhos // 81 >> +1 por conta do '\0'  
#define maxNome 81 
#define questoes 100 // editável
#define alunos 50   // editável

char validarAlternativas(){
    char c;
    do {
        scanf(" %c", &c);
        getchar(); //limpaR o '\n', enter
        c = tolower(c);
        if (c<'a' || c>'e'){
            printf("Informe uma alternativa válida (a, b, c, d ou e): ");
        }
    } while (c<'a' || c > 'e');
    return c;  
}

void preencherGabarito(char gabarito[questoes]){
    printf("\n================= GABARITO =================\n");
    for(int i=0; i<questoes; i++){
        printf("Questão %d: ", i + 1);
        gabarito[i] = validarAlternativas();
    }
}

void preencherRespostas(char respostas[alunos][questoes], char nomes[alunos][maxNome]){
    for(int i=0; i<alunos; i++){
        printf("\n================= PREENCHER =================\n");
        printf("\nInforme o nome do aluno %d: ", i + 1);
        setbuf(stdin, NULL);
        fgets(nomes[i], maxNome, stdin);
        //remover \n q o fgets pega
        nomes[i][strcspn(nomes[i], "\n")] = '\0'; //tem que ser entre colchetes!!
        
        for (int j = 0; j < questoes; j++) {
            printf("Resposta de %s - Questão %d: ", nomes[i], j + 1);
            respostas[i][j] = validarAlternativas();
        }
    }
}

void calcularAcertos(char res[alunos][questoes], char gab[questoes], int acertos[alunos]){
    for(int i=0; i<alunos; i++){
        acertos[i]=0;
        for (int j = 0; j < questoes; j++) {
            if(res[i][j] == gab[j]){
                acertos[i]++;
            }
        }
    }
}

void situacao(char nomes[alunos][maxNome], int acertos[alunos]){
    printf("\n================= RESULTADOS =================\n");
    
    for (int i = 0; i < alunos; i++) {
        if (acertos[i] >= 70) {
            printf("\nO aluno %s teve nota %d e está APROVADO.\n", nomes[i], acertos[i]);
        } 
        else {
            printf("\nO aluno %s obteve nota %d e está REPROVADO.\n", nomes[i], acertos[i]);
        }
    }
}

int main()
{
    char respostas[alunos][questoes];
    char gabarito[questoes];
    char nomes[alunos][maxNome];
    int acertos[alunos]; 

    preencherGabarito(gabarito);
    preencherRespostas(respostas, nomes);

    calcularAcertos(respostas, gabarito, acertos); 
    
    situacao(nomes, acertos);
    
    return 0;
}
