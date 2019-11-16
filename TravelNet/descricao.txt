Travel Network

O objetivo principal deste trabalho é implementar uma rede social de compartilhamento de agenda de viagens entre amigos. Nessa perspectiva, os usuários possuem um identificador único, um nome, e uma lista de amigos, e uma lista de agendamentos de viagens contendo informações sobre a data da viagem (dia, mês e ano), local de destino (nome da cidade e do país) e período de permanência no local de destino (quantidade de dias). Usuários que são amigos (isto é, usuários que estão, simultaneamente, na lista de amigos cada um), podem consultar a agenda de viagens uns dos outros para verificar possibilidades de encontros ocasionais durante suas viagens ou mesmo fazer uma planejamento conjunto afim de fazerem viagens juntos. Além disso, usuários podem cadastrar, buscar (listar todas ou filtrar por data de viagem e local de destino), alterar e remover agendamentos de viagens, fazer consultas sobre agendamento de viagens de amigos (listar todas ou filtrar por data de viagem e local de destino). Além disso, a rede social permite que o usuário cadastre, liste e remova amigos.


Restrições:

- A adição de amigos deve ser feita ao seguindo o modelo de fila, porém, a remoção deve ser aleatória dependendo do id informado (lembre-se de reajustar o a lista após remoções);

- A adição de viagens deve ser implementada como Árvore Binária de Busca, garantindo a ordem pela data da viagem;

- Agendamentos não podem possuir mesmos ids e nem serem sobrepostos, isto é, não é possível cadastrar um novo agendamento de viagem cujo o período total de permanência, contado à partir da data da viagem, se sobreponha com um agendamento previamente cadastrado.