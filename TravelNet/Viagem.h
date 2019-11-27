/*TAD do tipo Árvore Binária com
1. Data de Viagem (y/m/d, e.g. 19960414)
2. Local de destino (cidade e país)
3. Período de permanência no local de destino (em dias)
4. Ponteiro para o Filho Direito
5. Ponteiro para o Filho Esquerdo.
*/
typedef struct viagem Viagem;

//Cria um nó da árvore
Viagem *criaNoh(int *dataViagem, int permanencia, char **lugar);

//Compara duas datas para ver qual é a maior para fins de ordenação
int comparaData(int *data1, int *data2);

//Soma o tempo de permanência com a data de viagem, para verificar se 
//engloba outra viagem
int *somaDataEPermanencia(int *data, int permanencia);

//Inserindo um nó
Viagem *inserirNoh(Viagem *raiz, int *dataViagem, int permanencia, char **lugar);

//Busca um agendamento com base na data
Viagem *buscarPorData(Viagem *raiz, int *dataViagem);

//Busca um agendamento com base no destino
Viagem *buscarPorDestino(Viagem *raiz, char **lugar);


