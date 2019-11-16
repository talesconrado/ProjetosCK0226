#include "Cidade.h"

//Define a struct trajeto
typedef struct trajeto Trajeto;

//cria o trajeto
Trajeto *cria_trajeto(Cidade *prim, int horario_chegada, char *destino);

//retorna o destino do trajeto
char *mostra_destino(Trajeto *trajeto_x);

//retorna a primeira cidade
Cidade *mostra_cidade(Trajeto *trajeto_x);

//retorna o horario de chegada
int mostra_horario(Trajeto *trajeto_x);
