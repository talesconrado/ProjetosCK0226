#include <stdlib.h>
#include <stdio.h>
#include "Viagem.h"

typedef struct viagem{
    int *dataViagem;
    int permanencia;
    char **lugar;
    Viagem *direita;
    Viagem *esquerda;
};

//O nó será alocado futuramente apenas quando for necessário
//As suas operações de criação são as básicas
Viagem *criaNoh(int *dataViagem, int permanencia, char **lugar){
    Viagem *novoNoh = (Viagem *)malloc(sizeof(Viagem));
    novoNoh->dataViagem = dataViagem;
    novoNoh->permanencia = permanencia;
    novoNoh->lugar = lugar;
    novoNoh->direita = NULL;
    novoNoh->esquerda = NULL;

    return novoNoh;
}

//Aqui checa-se cada index da lista da data, para comparar a maior
//Por exemplo: data1[3] = 96,04,14, data2[3] = 96,04,18
//Comparamos os 96: OK, nem menor nem maior
//Comparamos os 04: OK, nem menor nem maior
//Comparamos os dias: Tem um maior que outro, achamos.
int comparaData(int *data1, int *data2){
    for (int i=0;i<3;++i){
        if (data1[i]<data2[i]){
            return 1;
        }
        if (data1[i]>data2[i]){
            return -1;
        }
    }
    return 0;
}

//Aqui é feito uma sequência de divisões dos dias de permanência
//checando se é maior que um ano, maior que um mês... e no fim 
//somamos o que sobrou.
int *somaDataEPermanencia(int *data, int permanencia){
    int *dataRetorno = (int*)malloc(3*sizeof(int));
    dataRetorno[0] = data[0];
    dataRetorno[1] = data[1];
    dataRetorno[2] = data[2];
    int anos = permanencia/365;
    if (anos >= 1){
        dataRetorno[0] += anos;
        permanencia -= 365 * anos;
    }
    int meses = permanencia/30;
    if (meses >= 1){
        dataRetorno[1] += meses;
        permanencia -= 30 * meses;
    }
    dataRetorno[2] += permanencia;

    return dataRetorno;
}

int checaSobreposicao(Viagem *raiz, int *dataViagem, int permanencia){
    Viagem *cursor = raiz;
    while (cursor != NULL){
        int *dataRetorno = somaDataEPermanencia(cursor->dataViagem, cursor->permanencia);
        int comparaSaida = comparaData(dataRetorno, dataViagem);
        if (comparaSaida<0){
            return 1;
        }
        else{
            cursor = cursor->esquerda;
        }
    }
    return 0;
}

Viagem *buscarPorData(Viagem *raiz, int *dataViagem){
    if (raiz==NULL){
        return NULL;
    }
    int compara;
    Viagem *cursor = raiz;
    while (cursor!=NULL){
        compara = comparaData(cursor->dataViagem, dataViagem);
        if (compara>0){
            cursor = cursor->direita;
        }
        else if (compara<0){
            cursor = cursor->esquerda;
        }
        else{
            return cursor;
        }
    }
    return cursor;
}

Viagem *inserirNoh(Viagem *raiz, int *dataViagem, int permanencia, char **lugar){
    if (raiz==NULL){
        raiz = criaNoh(dataViagem, permanencia, lugar);
    }
    else{
        if (buscarPorData(raiz, dataViagem) == NULL){
            int ehEsquerda = 0;
            int novoEhMaior = 0;
            Viagem *cursor = raiz;
            Viagem *anterior = NULL;
            while (cursor != NULL){
                novoEhMaior = comparaData(cursor->dataViagem, dataViagem);
                anterior = cursor;
                if (novoEhMaior>0){
                    ehEsquerda = 0;
                    cursor = cursor->direita;
                }
                else if(novoEhMaior<0){
                    ehEsquerda = 1;
                    cursor = cursor->esquerda;
                }
            }
            if (ehEsquerda){
                anterior->esquerda = criaNoh(dataViagem, permanencia, lugar);
            }
            else{
                anterior->direita = criaNoh(dataViagem, permanencia, lugar);
            }
        }
        else{
            printf("Já existe uma viagem cadastrada nesse dia.");
        }    
    }
    return raiz;
}


Viagem *removerNoh(Viagem *raiz, int *dataViagem){
    if (raiz == NULL){
        return NULL;
    }
    Viagem *cursor = raiz;
    int compara = comparaData(cursor->dataViagem, dataViagem);
    if (compara>0){
        raiz->direita = removerNoh(raiz->direita, dataViagem);
    }
    else if (compara<0){
        raiz->esquerda = removerNoh(raiz->esquerda, dataViagem);
    }
    else{
        
    }
}



int main(){
    int dataViagem[3] = {96,4,14};
    int permanencia = 2;
    char *lugar[2] = {"Tabuleiro1","Brasil"};

    int dataViagem2[3] = {96,4,9};
    int permanencia2 = 2;
    char *lugar2[2] = {"Tabuleiro2","Brasil"};

    int dataViagem3[3] = {96,4,17};
    int permanencia3 = 2;
    char *lugar3[2] = {"Tabuleiro3","Brasil"};
    
    Viagem *raiz = NULL;

    raiz = inserirNoh(raiz,dataViagem,permanencia,lugar);
    raiz = inserirNoh(raiz,dataViagem2,permanencia2,lugar2);
    raiz = inserirNoh(raiz,dataViagem3,permanencia3,lugar3);
    
    printf("%s",raiz->lugar[0]);
}

