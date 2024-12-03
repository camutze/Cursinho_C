#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura que os livros recebem.
/*Qualquer pessoa tem que entender seu codigo*/
struct biblioteca
{
    char titulo[50]; 
    char autor[50];
    int ano_pub;
    char isbn[13]; /*o que é isso?*/
    /* tenta usar um validador pra apagar*/
}; /*aqui precisa, nos outros não*/

//Função para apertar enter para continuar programa.
void enter_continuar()
{
    fflush(stdin);

    char enter[5];
    printf("Enter para continuar: ");
    scanf("%[^\n]", enter);
    printf("\n");
    return;
}; /*Esse ponto e virgula aqui, FEIO DEMAIS*/

//Função para mostrar o livro no id que o usuario digita.
void mostrar(int id, struct biblioteca livro[5], int qtd) /*estruturas sempre primeiro, struct biblioteca e depois os ints*/
{
    fflush(stdin);

    if (id < qtd && id >= 0)
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
    { /*quando tem um só comando, não colocar chaves nas funções if, while, for etc*/
        printf("Livro nao encontrado.\n");
    }
} /*QUE PONTO E VIRGULA È ESSE*/

//Função para mostrar o livro no título que o usuario digita.
void buscar_titulo(char titulo_busca[50], struct biblioteca livro[5], int qtd)
{
    fflush(stdin);
    
    /*Declarar variaveis antes de qualquer coisa */
    int i, j;
    int travar = 0; /*declara depois atribui*/
    int encontrado = 0;

    /*int i, j, travar, econtrado;*/



    int id = 0; /* declara as variaveis la em cima*/

    //Percorrendo os livros
    for (j = 0; j < qtd; j++)
    {
        travar = 0;
        //Percorrendo a letra dos livros
        for (i = 0; i <= (int)strlen(titulo_busca); i++)
        {
            //Se o i == ao tamanho do titulo que o usuário pesquisou, e nao tiver nenhuma letra errada, o livro foi encontrado
            if ((i == (int)strlen(titulo_busca)) && travar == 0)
            {
                /*um comando só*/
                encontrado = 1;
            }
            if (encontrado != 1)
            {
                if (tolower(titulo_busca[i]) == tolower(livro[j].titulo[i]) && travar != 1)
                {
                    /*um comando só*/
                    //Dando o id do livro enquanto estiver certo.
                    id = j;
                }
                else
                {
                    //Dando um id maior do que a quantidade de livro e travando pois nao é esse livro.
                    id = 6;
                    travar = 1;
                }
            }
        }
    }

    //Chamando a função mostrar o livro.
    mostrar(id, livro, qtd);
};


int main()
{
    int opcao = 10;
    int qtd = 0;
    int i, busca_id;
    int opc_busca = 10;


    //variavel livro recebendo a estrutura biblioteca
    /*declara structs primeiro*/
    struct biblioteca livro[5];

    while (opcao != 0)
    {
        /*podia ter colocado em uma função imprime menu*/
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
            
            //Se o numero maximo de livro não foi atingido.
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

                qtd += 1;
            }
            else
            {
                /*uma linha só, não usa chaves*/
                printf("Voce atingiu o numero maximo de livros.\n");
            }

            break;
        case 2: // Listar
            //Verificando se já possui algum livro cadastrado
            if (qtd > 0)
            {   
                //Loop para mostrar todos os livros, do id 0 até o último.
                for (i = 0; i < qtd; i++)
                {
                    /*apaga as chaves*/
                    mostrar(i, livro, qtd);
                }
            }
            else
            {
                /*pqp nao vou falar nada*/
                printf("Nenhum livro cadastrado.\n");
            }

            enter_continuar(); /*isso aqui ficou bom*/
            break;

        case 3: // Buscar
            
            while (opc_busca != 0)
            {
                printf("-------------------------\n");
                printf("Buscar\n");
                printf("(0) Sair\n");
                printf("(1) Buscar por id\n");
                printf("(2) Buscar por titulo\n");

                printf("Opcao: ");
                scanf("%d", &opc_busca);
                printf("-------------------------\n");

                switch (opc_busca)
                {
                
                case 1: //Buscar por id.
                    //Lendo o id.
                    printf("ID: ");
                    scanf("%d", &busca_id);
                    
                    /*espaços em branco demais*/
                    mostrar(busca_id - 1, livro, qtd); //-1 pois a posição no array começa com 0
                    
                    enter_continuar();
                break;
                    /*nao corrigiu depois -30*/
                    char titulo_busca[50]; //Por algum motivo tem que ser declarado aqui, voltar depois pra corrigir.
                case 2:
                    //Lendo o titulo
                    printf("Titulo: ");
                    fflush(stdin);
                    scanf("%[^\n]", titulo_busca);
                    
                    //Chamando a função buscar titulo, que printa o livro pesquisado.
                    buscar_titulo(titulo_busca, livro, qtd);
                    enter_continuar();
                break;    
                }
            }
            opc_busca = 10; //Declarei de novo, pois quando voltava pro menu principal e clicava no 3, o opc_busca já valia 0, aí fechava direto.
            break;

            
        }
    }

    //FIM
    return 0;
}