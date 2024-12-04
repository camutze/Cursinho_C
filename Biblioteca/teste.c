#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura que os livros recebem.
struct biblioteca
{
    int excluido;       //Variavel que indica 1 para excluido e 0 para nao excluido
    int ano_pub;       //Ano da publicaçãa
    char titulo[50];  //Titulo
    char autor[50];  //Autor
    char isbn[13];  //Uma espécie de "RG" para publicações como livros, revistas etc

};

// Função para apertar enter para continuar programa.
void enter_continuar()
{
    fflush(stdin);
    char enter[5];
    printf("Enter para continuar: ");
    scanf("%[^\n]", enter);
    printf("\n");
}

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
    else{
        printf("-------------------------\n");
        printf("id: %d\n", id+1);
        printf("Livro nao encontrado ou excluido.\n");
        printf("_________________________\n");
    }
    
}

// Função para mostrar o livro no título que o usuario digita.
void buscar_titulo(char titulo_busca[50], struct biblioteca livro[5], int qtd)
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

    // Chamando a função mostrar o livro.
    mostrar(livro, id, qtd);
};

int main()
{
    // variavel livro recebendo a estrutura biblioteca
    struct biblioteca livro[5];

    int opcao, qtd, i, busca_id, opc_busca, opc_excluir, opc_excluir_id, id, travar;
    opcao = 10;
    opc_busca = 10;
    opc_excluir = 10;
    opc_excluir_id = 10;
    qtd = 0;
    id = 0;
    travar = 0;

    while (opcao != 0)
    {
        printf("------------------------------\n");
        printf("(0) Sair\n");
        printf("(1) Cadastrar\n");
        printf("(2) Listar livros\n");
        printf("(3) Buscar Livro\n");
        printf("(4) Excluir livro\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("------------------------------\n");

        switch (opcao)
        {
        case 1: // Cadastrar

            // Se o numero maximo de livro não foi atingido.
            if (qtd < 5)
            {
                printf("------ Cadastrar ------\n");
                printf("ID: %d\n", qtd + 1);
                printf("Titulo: ");
                fflush(stdin);
                scanf("%[^\n]", livro[qtd].titulo);
                fflush(stdin);
                printf("Autor: ");
                scanf("%[^\n]", livro[qtd].autor);
                printf("Ano de publicacao: ");
                scanf("%d", &livro[qtd].ano_pub);
                printf("ISBN: ");
                scanf(" %s", livro[qtd].isbn);
                livro[qtd].excluido = 0;

                qtd += 1;
            }
            else
            {
                for(i = 0; i < qtd; i++){
                    if(livro[i].excluido == 1 && travar != 1){
                        id = i;
                        travar = 1;
                    }
                }

                if(travar == 1){
                    printf("------ Cadastrar ------\n");
                    printf("ID: %d\n", id + 1);
                    printf("Titulo: ");
                    fflush(stdin);
                    scanf("%[^\n]", livro[id].titulo);
                    fflush(stdin);
                    printf("Autor: ");
                    scanf("%[^\n]", livro[id].autor);
                    printf("Ano de publicacao: ");
                    scanf("%d", &livro[id].ano_pub);
                    printf("ISBN: ");
                    scanf(" %s", livro[id].isbn);
                    livro[id].excluido = 0;
                }
                else
                    printf("Voce atingiu o numero maximo de livros.\n");
            travar = 0; //Voltando ao valor inicial
            }

            break;
        case 2: // Listar
            // Verificando se já possui algum livro cadastrado
            if (qtd > 0)
            {
                // Loop para mostrar todos os livros, do id 0 até o último.
                for (i = 0; i < qtd; i++)
                    mostrar(livro, i, qtd);
            }
            else
                printf("Nenhum livro cadastrado.\n");

            enter_continuar();
            break;

        case 3: // Buscar

            while (opc_busca != 0)
            {
                printf("-------------------------\n");
                printf("Buscar\n");
                printf("(0) Voltar\n");
                printf("(1) Buscar por id\n");
                printf("(2) Buscar por titulo\n");

                printf("Opcao: ");
                scanf("%d", &opc_busca);
                printf("-------------------------\n");

                switch (opc_busca)
                {

                case 1: // Buscar por id.
                    // Lendo o id.
                    printf("ID: ");
                    scanf("%d", &busca_id);
                    mostrar(livro, busca_id - 1, qtd); //-1 pois a posição no array começa com 0
                    enter_continuar();
                break;

                    char titulo_busca[50]; // Por algum motivo tem que ser declarado aqui, voltar depois pra corrigir.
                case 2:
                    // Lendo o titulo
                    printf("Titulo: ");
                    fflush(stdin);
                    scanf("%[^\n]", titulo_busca);

                    // Chamando a função buscar titulo, que printa o livro pesquisado.
                    buscar_titulo(titulo_busca, livro, qtd);
                    enter_continuar();
                break;
                }
            }
            opc_busca = 10;
            break;

        case 4:

            while (opc_excluir != 0)
            {
                printf("Excluir\n");
                printf("(0) Voltar\n");
                printf("(1) Apagar por id\n");
                printf("(2) Apagar por titulo\n");

                printf("Opcao: ");
                scanf("%d", &opc_excluir);

                switch (opc_excluir)
                {
                case 1:
                    // Lendo o id.
                    printf("ID: ");
                    scanf("%d", &busca_id);

                    mostrar(livro, busca_id - 1, qtd); //-1 pois a posição no array começa com 0
                    if(busca_id <= qtd && busca_id > 0 && livro[busca_id - 1].excluido != 1){
                    while (opc_excluir_id != 0 && opc_excluir_id != 1)
                    {
                        printf("--------------------------------\n");
                        printf("Voce deseja apagar esse livro?\n");
                        printf("(0) nao\n");
                        printf("(1) apagar\n");
                        printf("Opcao: ");

                        scanf("%d", &opc_excluir_id);
                        printf("--------------------------------\n");

                        switch (opc_excluir_id)
                        {
                        case 1:
                            livro[busca_id - 1].excluido = 1;
                            break;
                        }
                    }
                    opc_excluir_id = 10;
                    }

                    break;

                default:
                    break;
                }
            }

            opc_excluir = 10; // Declarei de novo, pois quando voltava pro menu principal e clicava no 3, o opc_busca já valia 0, aí fechava direto.
            break;
        }
    }

    // FIM
    return 0;
}