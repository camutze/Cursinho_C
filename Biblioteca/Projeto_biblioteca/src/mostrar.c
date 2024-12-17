#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"mostrar.h"

// Função para mostrar o livro no id que o usuario digita.
void mostrar(struct biblioteca livro[5], int id, int qtd)
{
    fflush(stdin);

    if (id < qtd && id >= 0 && livro[id].excluido != 1)
    {
        printf("-------------------------\n");
        printf("id: %d\n", id + 1);
        printf("Titulo: %s\n", livro[id].titulo);
        printf("Autor: %s\n", livro[id].autor);
        printf("Ano de publicacao: %d\n", livro[id].ano_pub);
        printf("Cod. ISBN: %s\n", livro[id].isbn);
        printf("_________________________\n");
    }
    else
    {
        printf("-------------------------\n");
        printf("id: ?\n");
        printf("Livro nao encontrado ou excluido.\n");
        printf("_________________________\n");
    }
}