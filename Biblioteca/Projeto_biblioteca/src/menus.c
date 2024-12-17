#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "struct.h"

int menu_principal()
{
    int opcao;

    printf("------------------------------\n");
    printf("(0) Sair\n");
    printf("(1) Cadastrar\n");
    printf("(2) Listar livros\n");
    printf("(3) Buscar Livro\n");
    printf("(4) Excluir livro\n");

    printf("Opcao: ");
    scanf("%d", &opcao);
    printf("------------------------------\n");

    return opcao;
}

int menu_buscar()
{
    int opc_busca;
    printf("-------------------------\n");
    printf("//Pagina buscar\n");
    printf("(0) Voltar\n");
    printf("(1) Buscar por id\n");
    printf("(2) Buscar por titulo\n");

    printf("Opcao: ");
    scanf("%d", &opc_busca);
    printf("-------------------------\n");

    return opc_busca;
}

int menu_excluir()
{
    int opc_excluir;
    do
    {
        printf("//Pagina excluir\n");
        printf("(0) Voltar\n");
        printf("(1) Apagar por id\n");
        printf("(2) Apagar por titulo\n");

        printf("Opcao: ");
        scanf("%d", &opc_excluir);

    } while (opc_excluir < 0 || opc_excluir > 2);

    return opc_excluir;
}

int confirmar_exclusao(struct biblioteca livro[5], int busca_id)
{
    int opc_excluir_id;
    do
    {
        printf("--------------------------------\n");
        printf("Voce deseja apagar o livro %s?\n", livro[busca_id].titulo);
        printf("(0) nao\n");
        printf("(1) apagar\n");
        printf("Opcao: ");

        scanf("%d", &opc_excluir_id);
        printf("--------------------------------\n");
    } while (opc_excluir_id != 0 && opc_excluir_id != 1);

    return opc_excluir_id;
}
// Função para apertar enter para continuar programa.
void enter_continuar()
{
    fflush(stdin);
    char enter[5];
    printf("Enter para continuar: ");
    fflush(stdin);
    getchar(); // Limpa o '\n' deixado no buffer por entradas anteriores
    scanf("%[^\n]", enter);
    printf("\n");
}