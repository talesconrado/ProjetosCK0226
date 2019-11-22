/*TAD com 
1. ID
2. Nome
3. Lista de Amigos
4. Lista de Viagens
*/
typedef struct usuario Usuario;

//Criar um novo Usuário
Usuario *criarUsuario(int ID, char *nome);

//Retorna o ID do Usuário
int getUsuarioID(Usuario *user);
