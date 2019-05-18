#include "bibliotecas.h"
//união das bibliotecas

void *conect(void *arg);
void texto();

pthread_mutex_t mutex;

int main(int argc, char **argv)
{
	pthread_mutex_init(&mutex,NULL);
	int sock_fd, sock_len, sock_novo, num;
	socklen_t nock_novo_len;
	struct sockaddr_in sock_ser, sock_cli;
	char msg[100];

	sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
	//dominio AF_INET/tipo SOCK_STREAM/ protocol == 0
	
	if (sock_fd < 0)
	{
		printf("Erro ao criar o Socket \n");
			exit(0);
	}

	bzero((char*)&sock_ser, sizeof(sock_ser));
	//copia os bytes, cada um com um valor de zero, em string s ??????? 

	sock_ser.sin_family = AF_INET;
	//mostra o tipo de dominio utilizado domínio local (AF_UNIX) e domínio internet (AF_INET).
	sock_ser.sin_port=htons(9002);
	//endereça a porta 9002 como aberta para conexão para o código
	sock_ser.sin_addr.s_addr=INADDR_ANY;
	//aceita qualquer IP para conexão

	if (bind(sock_fd, (struct sockaddr*)&sock_ser, sizeof sock_ser) < 0)//associa um nome ao socket
		//descritor do socket/ struckt dos parametros do socket/ tamanho em bytesda struck 
	{
		printf("Erro ao associar o nome ao socket \n");
		exit(0);
	}

	//habilita servidor para ouvir client
	listen(sock_fd, 5);//descritor do socket/ num max de pedidos de acesso

	
	pthread_t conexao;
	//identifica o encadeamento, retorna pthread_create

	while (1)
	{
		int sock_novo_len = sizeof(sock_cli);
		
		//estabelece conexão entre cli/serv 
		sock_novo = accept(sock_fd, (struct sockaddr*)&sock_cli, &sock_novo_len);
		//descritor do socket/ end. da struckt que contem os dados de conexão do cliente/

		if (sock_novo < 0)
		{
			printf("Erro ao conectar com o cliente \n");
			exit(0);
		}
		
		else printf("\nConectado ao Servidor !\n\n");
		pthread_create(&conexao,NULL,conect,&sock_novo);
		//cria a thread /thread conexão/ atributo/ rotina conexão/ argumento 
	}
}

void *conect(void *arg)
{
	
	int save_sockt = *((int*) arg);
	//

	 char msg[255];
	 //tamanho da mensagem enviada pelo cliente
	
	memset(&msg,'\0', sizeof(msg));
	//preenche o bloco da memoria com um valor especifico
	//endereço inicial da memoria/ valor a ser preenchido/ num de bte a ser preenchido
 
	while (1)
	{
        pthread_mutex_lock(&mutex);
		//loca os recursos para uso exclusivo do do programa
        texto();
		printf("*********************************************\n");
		printf("\nExecute seu Comando:\n");
		read(save_sockt,&msg,255);

		printf("\nSeu comando foi: ");
		printf("%s",msg);
		printf("\n");
		
		//executa o comando no sistema
		system(msg);
		
		//libera os recursos para outra aplicação
		pthread_mutex_unlock(&mutex);
		printf("\n");
	}

}

void texto()
{
		//texto de apresentação do sistema
		printf("Trabalho Arq_Sis_Op\n");
 		printf("Comandos executados:\n");
 		printf("1- criar (sub)diretório / mkdir -p\n");
 		printf("2- remover (sub)diretório / rm -rf\n");
 		printf("3- entrar em (sub)diretório / cd\n");
 		printf("4- mostrar conteúdo do diretório / ls \n");
 		printf("5- criar arquivo / nano\n");
 		printf("6- remover arquivo / rm\n");
 		printf("7- escrever um sequência de caracteres em um arquivo / \n");
 		printf("8- mostrar conteúdo do arquivo / more\n\n");
}