#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"struct.h"

// Função que retorna o id do titulo que o usuario pesquisou
int buscar_titulo(char titulo_busca[50], struct biblioteca livro[5], int qtd)
{
    int i, j, travar, encontrado, id;
    travar = 0;
    encontrado = 0;
    id = 0;

    fflush(stdin);

    // Percorrendo os livros
    for (j = 0; j < qtd; j++)
    {
        travar = 0;
        // Percorrendo a letra dos livros
        for (i = 0; i <= (int)strlen(titulo_busca); i++)
        {
            // Se o i == ao tamanho do titulo que o usuário pesquisou, e nao tiver nenhuma letra errada, o livro foi encontrado
            if ((i == (int)strlen(titulo_busca)) && travar == 0)
                encontrado = 1;

            if (encontrado != 1)
            {
                if (tolower(titulo_busca[i]) == tolower(livro[j].titulo[i]) && travar != 1)
                    id = j; // Dando o id do livro enquanto estiver certo.

                else
                {
                    // Dando um id maior do que a quantidade de livro e travando pois nao é esse livro.
                    id = 6;
                    travar = 1;
                }
            }
        }
    }

    // Retornando o id do livro buscado.
    return (id);
};