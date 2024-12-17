#ifndef STRUCT_H
#define STRUCT_H

// Estrutura que os livros recebem.
struct biblioteca
{
    int excluido;    // Variavel que indica 1 para excluido e 0 para nao excluido
    int ano_pub;     // Ano da publicaçãa
    char titulo[50]; // Titulo
    char autor[50];  // Autor
    char isbn[13];   // Uma espécie de "RG" para publicações como livros, revistas etc
};

#endif