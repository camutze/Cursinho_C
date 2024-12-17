#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "struct.h"
#include "mostrar.h"
#include "buscar_titulo.h"

int main()
{

    // variavel livro recebendo a estrutura biblioteca
    struct biblioteca livro[5];

    int opcao, qtd, travar, id, i, opc_busca, busca_id, opc_excluir, opc_excluir_id;
    opcao = 0;
    qtd = 0;
    travar = 0;
    id = 0;
    opc_busca = 0;

    do
    {
        opcao = menu_principal();

        switch (opcao)
        {
        case 1: // Cadastrar

            // Se o numero maximo de livro não foi atingido.
            if (qtd < 5)
            {
                cadastrar(livro, qtd); // Função que cadastra o livro
                qtd += 1;
            }
            else
            {
                // Percorrendo para ver se possuimos algum livro excluido
                for (i = 0; i < qtd; i++)
                {
                    if (livro[i].excluido == 1 && travar != 1)
                    {
                        // Se existe falamos qual o id e paramos de percorrer os outros livros
                        id = i;
                        travar = 1;
                    }
                }

                // se possuimos algum livro excluido
                if (travar == 1)
                {
                    cadastrar(livro, id); //Função que cadastra livro
                }
                else
                {
                    printf("Voce atingiu o numero maximo de livros.\n");
                }
                travar = 0; // Voltando ao valor inicial, travar = falso
            }

            break;

        case 2:
            // Listar
            // Verificando se já possui algum livro cadastrado
            if (qtd > 0)
            {
                // Loop para mostrar todos os livros, da posicao 0 até o último.
                for (i = 0; i < qtd; i++)
                    mostrar(livro, i, qtd);
            }
            else
                printf("Nenhum livro cadastrado.\n");

            enter_continuar();
            break;

        case 3: // Buscar

            do
            {
                opc_busca = menu_buscar(); //Mostrando menu/   (1) Buscar por id  / (2) Buscar por titulo

                switch (opc_busca)
                {

                case 1: // Buscar por id.
                    // Lendo o id.
                    printf("ID: ");
                    scanf("%d", &busca_id);
                    mostrar(livro, busca_id - 1, qtd); //-1 pois a posição no array começa com 0
                    enter_continuar();
                    break;
                    char titulo_busca[50];
                case 2:
                    // Lendo o titulo
                    printf("Titulo: ");
                    fflush(stdin);
                    getchar();
                    scanf("%[^\n]", titulo_busca);

                    // Chamando a funcao que printa o livro pesquisado.
                    mostrar(livro, buscar_titulo(titulo_busca, livro, qtd), qtd);
                    enter_continuar();
                    break;
                }
            } while (opc_busca != 0);
            break;
        case 4:

            do
            {
                opc_excluir = menu_excluir();

                switch (opc_excluir)
                {
                case 1:
                    // Lendo o id.
                    printf("ID: ");
                    scanf("%d", &busca_id);

                    mostrar(livro, busca_id - 1, qtd); //-1 pois a posição no array começa com 0
                    if (busca_id <= qtd && busca_id > 0 && livro[busca_id - 1].excluido != 1)
                    {
                        opc_excluir_id = confirmar_exclusao(livro, busca_id - 1);

                        switch (opc_excluir_id)
                        {
                        case 1:
                            livro[busca_id - 1].excluido = 1;
                            printf("EXCLUIDO!\n");
                            enter_continuar();
                            break;
                        };
                    }

                    break;
                    char titulo_busca[50];
                case 2:
                    // Lendo o titulo
                    printf("Titulo: ");
                    fflush(stdin);
                    getchar();
                    scanf("%[^\n]", titulo_busca);

                    // Chamando a função buscar titulo, que printa o livro pesquisado.
                    busca_id = buscar_titulo(titulo_busca, livro, qtd);
                    mostrar(livro, busca_id, qtd);
                    if (busca_id <= qtd && busca_id >= 0 && livro[busca_id].excluido != 1)
                    {
                        opc_excluir_id = confirmar_exclusao(livro, busca_id);

                        switch (opc_excluir_id)
                        {
                        case 1:
                            livro[busca_id].excluido = 1;
                            printf("EXCLUIDO!\n");
                            enter_continuar();
                            break;
                        }
                    }
                    break;
                }
            } while (opc_excluir != 0);

            break;
        }
    } while (opcao != 0);
    return 0;
}