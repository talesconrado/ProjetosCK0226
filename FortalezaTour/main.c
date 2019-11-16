#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Cidade.h"
#include "Trajeto.h"

//cria a sequencia de cidades do trajeto
Trajeto *cria_rota(int *prototipo, int horario, int tamanho, char **lista_de_nomes, char **lista_de_car){
    Cidade *prim = criar_cidade(lista_de_nomes[prototipo[1]], lista_de_car[prototipo[1]]);
    Cidade *aux = prim;
    for (int i=2; i<=tamanho;i++){
        Cidade *nova_cidade = criar_cidade(lista_de_nomes[prototipo[i]], lista_de_car[prototipo[i]]);
        if (i==2){
            adiciona_prox(prim, nova_cidade);
        }
        else{
            adiciona_prox(aux, nova_cidade);
        }
        aux = nova_cidade;    
    }

    Trajeto *novo_trajeto = cria_trajeto(prim, horario, lista_de_nomes[prototipo[tamanho]]);
    return novo_trajeto;
}

//encontra a rota mais adequada, dado um horário de chegada e um destino
int melhor_rota(int horario, char *destino, Trajeto **lista_de_rotas){
    int melhor_horario = 2400;
    int melhor_rota = -1;
    for (int i=0;i<20;i++){
        char *destino_atual = mostra_destino(lista_de_rotas[i]);
        if (strcmp(destino, destino_atual)==0){
            int tmp = mostra_horario(lista_de_rotas[i]);
            int dist_do_ideal = abs(horario-tmp);
            if (dist_do_ideal < melhor_horario){
                melhor_horario = dist_do_ideal;
                melhor_rota = i;
            }
        }
    }
    return melhor_rota;
}

void navegar(Trajeto **lista_de_rotas, int posicao){
    printf("\nPressione '2' para ir para a próxima cidade ou '1' para voltar.\n");
    printf("Se desejar sair digite '3', se desejar conhecer outras rotas digite '4'.\n");
    printf("--------------\nINÍCIO DA VIAGEM\n");
    Cidade *cidade_atual = mostra_cidade(lista_de_rotas[posicao]);
    apresenta_cidade(cidade_atual);
    int opcao;
    printf("\n");
    scanf("\n%d", &opcao);
    while (opcao != 3){
        if (opcao == 2){
            if (prox_cidade(cidade_atual)!= NULL){
                cidade_atual = prox_cidade(cidade_atual);
                apresenta_cidade(cidade_atual);
            }
            else{
            printf("\nFim da rota.\n");
            }
        }

        if (opcao == 1){
            if (ant_cidade(cidade_atual)!= NULL){
                cidade_atual = ant_cidade(cidade_atual);
                apresenta_cidade(cidade_atual);
            }
            else{
                printf("\nFim da rota.\n");
            }
        }
        if (opcao == 4){
            printf("\nQue cidade deseja conhecer?\n");
            char destino[25];
            scanf("%s", destino);
            int melhor = melhor_rota(1600, destino, lista_de_rotas);
            navegar(lista_de_rotas, melhor);
            printf("\nObrigado por usar o nosso serviço!");
            break;
        }
    
        printf("\n");
        scanf("\n%d", &opcao);
    }
}

int main(){

    //CIDADES + DESCRIÇÕES
    //FORTALEZA

    char fortaleza_nome[] = "Fortaleza";
    char fortaleza_car[] = "Terra da luz";    
    
    //TABULEIRO
    char tabuleiro_nome[] = "Tabuleiro-do-Norte";
    char tabuleiro_car[] = "A cidade dos caminhoneiros";
    
    //LIMOEIRO
    char limoeiro_nome[] = "Limoeiro";
    char limoeiro_car[] = "A princesinha do vale";

    //RUSSAS
    char russas_nome[] = "Russas";
    char russas_car[] = "A capital do vale";
 
    //ARACATI
    char aracati_nome[] = "Aracati";
    char aracati_car[] = "Terra dos bons ventos";
  
    //MORADA NOVA
    char morada_nome[] = "Morada-Nova";
    char morada_car[] = "Terra da festa do vaqueiro";
 
    //IGUATU 
    char iguatu_nome[] = "Iguatu";
    char iguatu_car[] = "Terra da telha";
 
    //QUIXADÁ
    char quixada_nome[] = "Quixada";
    char quixada_car[] = "Terra dos monólitos";
  
    //JUAZEIRO DO NORTE
    char juazeiro_nome[] = "Juazeiro-do-Norte";
    char juazeiro_car[] = "Terra do Padre Cícero";
  
    //CANINDÉ
    char caninde_nome[] = "Caninde";
    char caninde_car[] = "Terra de São Francisco";
  
    //TIANGUÁ
    char tiangua_nome[] = "Tiangua";
    char tiangua_car[] = "A capital de Ibiapaba";
  
    //CRATO
    char crato_nome[] = "Crato";
    char crato_car[] = "Coração do Ceará";

    char *lista_cidades_nomes[] = {fortaleza_nome, russas_nome, limoeiro_nome, tabuleiro_nome,
                                aracati_nome, morada_nome, iguatu_nome, quixada_nome, juazeiro_nome,
                                caninde_nome, tiangua_nome, crato_nome};

    char *lista_cidades_car[] = {fortaleza_car, russas_car, limoeiro_car, tabuleiro_car,
                                aracati_car, morada_car, iguatu_car, quixada_car, juazeiro_car,
                                caninde_car, tiangua_car, crato_car};


    //"protótipo" das rotas

    int rota1[] = {4,0,1,2,3};
    int rota2[] = {3,0,1,2};
    int rota3[] = {2,0,1};
    int rota4[] = {2,0,4};
    int rota5[] = {3,0,1,5};
    int rota6[] = {5,0,1,4,5,6};
    int rota7[] = {5,0,2,5,3,7};
    int rota8[] = {4,0,4,7,8};
    int rota9[] = {4,0,5,6,4,9};
    int rota10[] = {6,0,2,3,5,6,10};
    int rota11[] = {6,0,2,3,7,9,11};

    int *lista_prototipos[] = {rota1,rota2,rota3,rota4,rota5,rota6,rota7,rota8,rota9,rota10,rota11,rota1,
                                rota2,rota3,rota4,rota5,rota6,rota8,rota10,rota11};
    
    int horarios[] = {500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,400};

    //criaçã das rotas

    Trajeto *lista_de_rotas[20];
    
    for (int i=0;i<20;i++){
        lista_de_rotas[i] = cria_rota(lista_prototipos[i], horarios[i],lista_prototipos[i][0],lista_cidades_nomes,lista_cidades_car);
    }
    
    char destino[25];
    printf("Bem vindo ao sistema virtual de ônibus, TC Viagens!\n"
           "No momento não temos muitas linhas ainda, mas estamos trabalhando para\n"
            "melhor atendê-lo em breve!"
            "\n\nPara começar, digite o nome da cidade que você deseja ir, separado por hífen:\n");
    scanf("%s",destino);
    printf("Agora digite o horário que você gostaria de chegar no seguinte formato: 11:00am virará 1100\n");
    int horario;
    scanf("%d",&horario);
    int achou = melhor_rota(horario, destino, lista_de_rotas);
    if (achou != -1){
        printf("\nAchamos a rota ideal para você!\n");
        printf("A rota número: %d!\n", achou+1);
        printf("\nHorário de chegada: %d horas\n",mostra_horario(lista_de_rotas[achou])/100);
        printf("\nIremos te levar até ela virtualmente para que você possa navegar pelos destinos que você encontrará no caminho ;)\n");
        navegar(lista_de_rotas, achou);
    }
    else{
        printf("\nAinda não atendemos essa cidade ou não conseguimos entender direito o que você digitou :/\n");
    }

    return 0;
}