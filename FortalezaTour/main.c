#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct que segurará os nomes das cidades e seu lema
typedef struct Cidade{
    char *nome_cidade;
    char *caracteristica;
} cidade;

//Lista encadeada dupla com o caminho feito por uma linha
typedef struct Trajeto{
    struct Trajeto *prox;
    struct Trajeto *ant;
    cidade *atual;  
} trajeto;

typedef struct Linha{
    trajeto *inicio;
    char *destino;
    int hora_chegada;
} linha;

//Função para checar o melhor tempo até uma cidade X
//ou seja, a rota ideal para um dado passageiro 
int rota_ideal(char *nome_cidade, linha *rotas, int hora){
    int i = 0;
    char *morada_new = "Morada";
    if (strcmp(nome_cidade, morada_new)==0){
        int r1 = abs(hora-(rotas[6].hora_chegada));
        int r2 = abs(hora-(rotas[10].hora_chegada));
        if (r1<r2){
            return 6;
        }
        else{
            return 10;
        }
    }
    while (i<11){
        if (strcmp(rotas[i].destino,nome_cidade)==0){
            return i;
        }
        ++i;
    }
    return -1;
}

//Navegar entre rotas
cidade *navegacao(trajeto *inicio){
    int input;
    printf("\nUse 1 (esquerda) e 2 (direita )para navegar. Ou qualquer outra coisa para sair.\n");
    printf("\n\n%s\n", inicio->atual->nome_cidade);
    printf("%s\n", inicio->atual->caracteristica);
    scanf("%d",&input);
    while (input==1 || input==2){
        if (input==2){
            if (inicio->prox != NULL){
                inicio = inicio->prox;
                printf("\n\n%s\n", inicio->atual->nome_cidade);
                printf("%s\n", inicio->atual->caracteristica);
            }
            else{
                printf("\nFim da rota.\n");
            }
        }
        if (input==1){
            if (inicio->ant != NULL){
                inicio = inicio->ant;
                printf("\n\n%s\n", inicio->atual->nome_cidade);
                printf("%s\n", inicio->atual->caracteristica);
            }
            else{
                printf("\nFim da rota.\n");
            }
        }
    
        scanf("%d",&input);

    }
    
}


int main(){

    //TODO: Criar 10 rotas + Descriçoes
    //CIDADES + DESCRIÇÕES

    //FORTALEZA
    char fortaleza_nome[] = "Fortaleza";
    char fortaleza_car[] = "Terra da luz";
    
    cidade *fortaleza = (cidade*)malloc(sizeof(cidade));
    fortaleza->nome_cidade = fortaleza_nome;
    fortaleza->caracteristica = fortaleza_car;
    
    //TABULEIRO
    char tabuleiro_nome[] = "Tabuleiro";
    char tabuleiro_car[] = "A cidade dos caminhoneiros";
    
    cidade *tabuleiro = (cidade*)malloc(sizeof(cidade));
    tabuleiro->nome_cidade = tabuleiro_nome;
    tabuleiro->caracteristica = tabuleiro_car;
    
    //LIMOEIRO
    char limoeiro_nome[] = "Limoeiro";
    char limoeiro_car[] = "A princesinha do vale";

    cidade *limoeiro = (cidade*)malloc(sizeof(cidade));
    limoeiro->nome_cidade = limoeiro_nome;
    limoeiro->caracteristica = limoeiro_car;

    //RUSSAS
    char russas_nome[] = "Russas";
    char russas_car[] = "A capital do vale";

    cidade *russas = (cidade*)malloc(sizeof(cidade));
    russas->nome_cidade = russas_nome;
    russas->caracteristica = russas_car;

    //ARACATI
    char aracati_nome[] = "Aracati";
    char aracati_car[] = "Terra dos bons ventos";

    cidade *aracati = (cidade*)malloc(sizeof(cidade));
    aracati->nome_cidade = aracati_nome;
    aracati->caracteristica = aracati_car;

    //MORADA NOVA
    char morada_nome[] = "Morada";
    char morada_car[] = "Terra da festa do vaqueiro";

    cidade *morada = (cidade*)malloc(sizeof(cidade));
    morada->nome_cidade = morada_nome;
    morada->caracteristica = morada_car;

    //IGUATU 
    char iguatu_nome[] = "Iguatu";
    char iguatu_car[] = "Terra da telha";

    cidade *iguatu = (cidade*)malloc(sizeof(cidade));
    iguatu->nome_cidade = iguatu_nome;
    iguatu->caracteristica = iguatu_car;

    //QUIXADÁ
    char quixada_nome[] = "Quixadá";
    char quixada_car[] = "Terra dos monólitos";

    cidade *quixada = (cidade*)malloc(sizeof(cidade));
    quixada->nome_cidade = quixada_nome;
    quixada->caracteristica = quixada_car;

    //JUAZEIRO DO NORTE
    char juazeiro_nome[] = "Juazeiro";
    char juazeiro_car[] = "Terra do Padre Cícero";

    cidade *juazeiro = (cidade*)malloc(sizeof(cidade));
    juazeiro->nome_cidade = juazeiro_nome;
    juazeiro->caracteristica = juazeiro_car;

    //CANINDÉ
    char caninde_nome[] = "Canindé";
    char caninde_car[] = "Terra de São Francisco";

    cidade *caninde = (cidade*)malloc(sizeof(cidade));
    caninde->nome_cidade = caninde_nome;
    caninde->caracteristica = caninde_car;

    //TIANGUÁ
    char tiangua_nome[] = "Tianguá";
    char tiangua_car[] = "A capital de Ibiapaba";

    cidade *tiangua = (cidade*)malloc(sizeof(cidade));
    tiangua->nome_cidade = tiangua_nome;
    tiangua->caracteristica = tiangua_car;

    //CRATO
    char crato_nome[] = "Crato";
    char crato_car[] = "Coração do Ceará";

    cidade *crato = (cidade*)malloc(sizeof(cidade));
    crato->nome_cidade = crato_nome;
    crato->caracteristica = crato_car;

    //

    //FORTALEZA->RUSSAS->LIMOEIRO->TABULEIRO
    //SAÍDA 6AM
    //CHEGADA 10AM
    trajeto *tabuleiro1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *tabuleiro2 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *tabuleiro3 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *tabuleiro4 = (trajeto*)malloc(sizeof(trajeto));
    
    linha *Tabuleiro = (linha*)malloc(sizeof(linha));
    Tabuleiro->destino = tabuleiro_nome;
    Tabuleiro->hora_chegada = 1000;
    Tabuleiro->inicio = tabuleiro1; 

    
    tabuleiro1->atual = fortaleza;
    tabuleiro1->prox = tabuleiro2;
    tabuleiro1->ant = NULL;

    tabuleiro2->atual = russas;
    tabuleiro2->prox = tabuleiro3;
    tabuleiro2->ant = tabuleiro1;

    tabuleiro3->atual = limoeiro;
    tabuleiro3->prox = tabuleiro4;
    tabuleiro3->ant = tabuleiro2;

    tabuleiro4->atual = tabuleiro;
    tabuleiro4->prox = NULL;
    tabuleiro4->ant = tabuleiro3;

    
     //FORTALEZA->RUSSAS->LIMOEIRO
    //SAÍDA 7AM
    //CHEGADA 9:30AM
    linha *Limoeiro = (linha*)malloc(sizeof(linha));

    trajeto *limoeiro1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *limoeiro2 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *limoeiro3 = (trajeto*)malloc(sizeof(trajeto));
    
    Limoeiro->destino = limoeiro_nome;
    Limoeiro->hora_chegada = 930;
    Limoeiro->inicio = limoeiro1; 

    
    limoeiro1->atual = fortaleza;
    limoeiro1->prox = limoeiro2;
    limoeiro1->ant = NULL;

    limoeiro2->atual = russas;
    limoeiro2->prox = limoeiro3;
    limoeiro2->ant = limoeiro1;

    limoeiro3->atual = limoeiro;
    limoeiro3->prox = NULL;
    limoeiro3->ant = limoeiro2;


    //FORTALEZA->RUSSAS
    //SAÍDA 8AM
    //CHEGADA 11AM
    linha *Russas = (linha*)malloc(sizeof(linha));

    trajeto *russas1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *russas2 = (trajeto*)malloc(sizeof(trajeto));
    
    Russas->destino = russas_nome;
    Russas->hora_chegada = 1100;
    Russas->inicio = russas1; 

    russas1->atual = fortaleza;
    russas1->prox = russas2;
    russas1->ant = NULL;

    russas2->atual = russas;
    russas2->prox = NULL;
    russas2->ant = russas1;


    //FORTALEZA->IGUATU->Aracati
    //SAÍDA: 8AM
    //CHEGADA: 12AM

    linha *Aracati = (linha*)malloc(sizeof(linha));

    trajeto *aracati1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *aracati2 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *aracati3 = (trajeto*)malloc(sizeof(trajeto));

    Aracati->destino = aracati_nome;
    Aracati->hora_chegada = 1200;
    Aracati->inicio = aracati1; 

    aracati1->atual = fortaleza;
    aracati1->prox = aracati2;
    aracati1->ant = NULL;

    aracati2->atual = iguatu;
    aracati2->prox = aracati3;
    aracati2->ant = aracati1;

    aracati3->atual = aracati;
    aracati3->prox = NULL;
    aracati3->ant = aracati2;

    //FORTALEZA->MORADA NOVA->JUAZEIRO
    //ROTA 5
    //SAIDA: 8AM
    //CHEGADA: 16AM

    linha *Juazeiro = (linha*)malloc(sizeof(linha));

    trajeto *juazeiro1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *juazeiro2 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *juazeiro3 = (trajeto*)malloc(sizeof(trajeto));

    Juazeiro->destino = juazeiro_nome;
    Juazeiro->hora_chegada = 1600;
    Juazeiro->inicio = juazeiro1; 

    juazeiro1->atual = fortaleza;
    juazeiro1->prox = juazeiro2;
    juazeiro1->ant = NULL;

    juazeiro2->atual = morada;
    juazeiro2->prox = juazeiro3;
    juazeiro2->ant = juazeiro1;

    juazeiro3->atual = juazeiro;
    juazeiro3->prox = NULL;
    juazeiro3->ant = juazeiro2;    

    //ROTA 6
    //FORTALEZA->ARACATI->IGUATU
    //CHEGADA: 17AM

    linha *Iguatu = (linha*)malloc(sizeof(linha));

    trajeto *iguatu1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *iguatu2 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *iguatu3 = (trajeto*)malloc(sizeof(trajeto));

    Iguatu->destino = iguatu_nome;
    Iguatu->hora_chegada = 1700;
    Iguatu->inicio = iguatu1; 

    iguatu1->atual = fortaleza;
    iguatu1->prox = iguatu2;
    iguatu1->ant = NULL;

    iguatu2->atual = aracati;
    iguatu2->prox = iguatu3;
    iguatu2->ant = iguatu1;

    iguatu3->atual = iguatu;
    iguatu3->prox = NULL;
    iguatu3->ant = iguatu2;

    //ROTA 7
    //FORTALEZA->MORADA NOVA
    //CHEGADA 18h

    linha *MoradaNova = (linha*)malloc(sizeof(linha));
    
    trajeto *morada1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *morada2 = (trajeto*)malloc(sizeof(trajeto));

    MoradaNova->destino = morada_nome;
    MoradaNova->hora_chegada = 1800;
    MoradaNova->inicio = morada1; 

    morada1->atual = fortaleza;
    morada1->prox = morada2;
    morada1->ant = NULL;

    morada2->atual = morada;
    morada2->prox = NULL;
    morada2->ant = morada1;
    
    //ROTA 8
    //CHEGADA 19H
    //FORTALEZA->ARACATI->QUIXADÁ

    linha *Quixada = (linha*)malloc(sizeof(linha));
    
    trajeto *quixada1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *quixada2 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *quixada3 = (trajeto*)malloc(sizeof(trajeto));

    Quixada->destino = quixada_nome;
    Quixada->hora_chegada = 1900;
    Quixada->inicio = quixada1; 

    quixada1->atual = fortaleza;
    quixada1->prox = quixada2;
    quixada1->ant = NULL;

    quixada2->atual = aracati;
    quixada2->prox = quixada3;
    quixada2->ant = quixada1;

    quixada3->atual = quixada;
    quixada3->prox = NULL;
    quixada3->ant = quixada2;
    
    //ROTA 9
    //FORTALEZA CRATO CANINDÉ
    //CHEGADA 21H
    
    linha *Caninde = (linha*)malloc(sizeof(linha));
    
    trajeto *caninde1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *caninde2 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *caninde3 = (trajeto*)malloc(sizeof(trajeto));

    Caninde->destino = aracati_nome;
    Caninde->hora_chegada = 2100;
    Caninde->inicio = aracati1; 

    caninde1->atual = fortaleza;
    caninde1->prox = caninde2;
    caninde1->ant = NULL;

    caninde2->atual = crato;
    caninde2->prox = caninde3;
    caninde2->ant = caninde1;

    caninde3->atual = caninde;
    caninde3->prox = NULL;
    caninde3->ant = caninde2;
    
    //ROTA 10
    //FORTALEZA CRATO 
    //CHEGADA 23H
    linha *Crato = (linha*)malloc(sizeof(linha));

    trajeto *crato1 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *crato2 = (trajeto*)malloc(sizeof(trajeto));
   
    Crato->destino = crato_nome;
    Crato->hora_chegada = 2300;
    Crato->inicio = crato1; 

    crato1->atual = fortaleza;
    crato1->prox = crato2;
    crato1->ant = NULL;

    crato2->atual = crato;
    crato2->prox = NULL;
    crato2->ant = crato1;

    //ROTA 11
    //FORTALEZA->MORADA NOVA
    //CHEGADA 19h

    linha *MoradaNova2 = (linha*)malloc(sizeof(linha));
    
    trajeto *morada3 = (trajeto*)malloc(sizeof(trajeto));
    trajeto *morada4 = (trajeto*)malloc(sizeof(trajeto));

    MoradaNova2->destino = morada_nome;
    MoradaNova2->hora_chegada = 1900;
    MoradaNova2->inicio = morada3; 

    morada3->atual = fortaleza;
    morada3->prox = morada4;
    morada3->ant = NULL;

    morada4->atual = morada;
    morada4->prox = NULL;
    morada4->ant = morada3;

    linha rotas[11] = {*Tabuleiro, *Limoeiro, 
    *Russas, *Aracati, *Iguatu, *Juazeiro, *MoradaNova, *Quixada, *Caninde, *Crato, *MoradaNova2};

    char nome[20];
    printf("Bem vindo ao sistema virtual de ônibus, TC Viagens!\n"
           "No momento não temos muitas linhas ainda (10 no total), mas estamos trabalhando para\n"
            "melhor atendê-lo em breve!"
            "\n\nPara começar, digite o primeiro nome da cidade para onde você deseja ir:\n");
    scanf("%s",nome);
    printf("Agora digite o horário que você gostaria de chegar no seguinte formato: 11:00am virará 1100\n");
    int hora;
    scanf("%d",&hora);
    int achou = rota_ideal(nome, rotas, hora);
    if (achou != -1){
        printf("\nAchamos a rota ideal para você!\n");
        printf("A rota número: %d!\n", achou);
        printf("\nIremos te levar até ela para que você possa navegar pelos destinos que você encontrará no caminho!\n");
        trajeto *comeco = rotas[achou].inicio;
        navegacao(comeco);
    }
    else{
        printf("\nAinda não atendemos essa cidade ou não conseguimos entender direito o que você digitou :/\n");
    }

    
    return 0;
}