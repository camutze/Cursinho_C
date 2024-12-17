#include<stdio.h>
#include<stdlib.h>
#include"cadastrar.h"
#include"struct.h"

void cadastrar(struct biblioteca livro[5], int posicao)
{
    fflush(stdin);
    printf("------ Cadastrar ------\n");
    printf("ID: %d\n", posicao + 1);
    printf("Titulo: ");
    fflush(stdin);
    getchar(); // Limpa o '\n' deixado no buffer por entradas anteriores
    scanf("%[^\n]", livro[posicao].titulo);
    getchar();
    fflush(stdin);
    printf("Autor: ");
    scanf("%[^\n]", livro[posicao].autor);
    fflush(stdin);
    printf("Ano de publicacao: ");
    scanf("%d", &livro[posicao].ano_pub);
    printf("ISBN: ");
    scanf(" %s", livro[posicao].isbn);
    livro[posicao].excluido = 0;
}