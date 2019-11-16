#include <stdio.h>
#include <stdlib.h>
#include "Trajeto.h"
#include "Cidade.h"

struct trajeto{
    Cidade *prim;
    int horario_chegada;
    char *destino;
};

Trajeto *cria_trajeto(Cidade *prim, int horario_chegada, char *destino){
    Trajeto *novo_trajeto = (Trajeto*)malloc(sizeof(Trajeto));
    novo_trajeto->prim = prim;
    novo_trajeto->horario_chegada = horario_chegada;
    novo_trajeto->destino = destino;

    return novo_trajeto;
}

char *mostra_destino(Trajeto *trajeto_x){
    return trajeto_x->destino;
}

Cidade *mostra_cidade(Trajeto *trajeto_x){
    return trajeto_x->prim;
}

int mostra_horario(Trajeto *trajeto_x){
    return trajeto_x->horario_chegada;
}


