#include <stdio.h>
#include <stdlib.h>
#include "Cidade.h"

struct cidade{
    char *nome_cidade;
    char *caracteristica;
    Cidade *prox;
    Cidade *ant;
};


Cidade *criar_cidade(char *nome, char *caracteristica){
    Cidade *nova_cidade = (Cidade*)malloc(sizeof(Cidade));
    nova_cidade->nome_cidade = nome;
    nova_cidade->caracteristica = caracteristica;
    nova_cidade->prox = NULL;
    nova_cidade->ant = NULL;

    return nova_cidade;
}

Cidade *adiciona_prox(Cidade *atual, Cidade *prox){
    atual->prox = prox;
    prox->ant = atual;
    
    return prox;
}

Cidade *prox_cidade(Cidade *atual){
    return atual->prox;
}

Cidade *ant_cidade(Cidade *atual){
    return atual->ant;
}

void apresenta_cidade(Cidade *atual){
    printf("\n%s", atual->nome_cidade);
    printf("\n%s", atual->caracteristica);
}

