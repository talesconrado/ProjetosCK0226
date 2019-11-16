#include <stdio.h>
#include <stdlib.h>

//Definindo a struct cidade que armazena as informações
typedef struct cidade Cidade;

//Criar uma nova cidade e aloca espaço na memória
Cidade *criar_cidade(char *nome, char *caracteristica);

//Adicionar a próxima cidade
Cidade *adiciona_prox(Cidade *atual, Cidade*prox);

//retorna a próxima cidade
Cidade *prox_cidade(Cidade *atual);

//retorna a cidade anterior
Cidade *ant_cidade(Cidade *atual);

//mostra o nome a característica da cidade
void apresenta_cidade(Cidade *atual);

//navega pelas cidades
