//TESTE DE Servidor
/*
    Para compilar no terminal use:
    gcc servidor.c -lpthread -o servidor
    Servidor para Thread
*/
#include "bibliotecas.h"						//União das bibliotecas

//Declaração função que usara thread
void *conecLeitor(void *);

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;
     
    //Criar o socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Não foi possível criar o soquete");
    }
    puts("Socket criado");

    //Preparar o sockaddr_in em uma estrutura
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9002);

	sock_fd = socket(AF_INET, SOCK_STREAM, 0); 
	//dominio AF_INET/tipo SOCK_STREAM/ protocol == 0

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
		int esc = 0;
		char camp;
	    char cbsh = '. ./bashcd.sh';
        printf("Digite 1 se quer executar os comandos normais e 2 se quser torcar de pasta");
		
		switch (save_sockt)
		{
		case 1:

			pthread_mutex_lock(&mutex);
			//loca os recursos para uso exclusivo do do programa
        	texto();
			printf("*********************************************\n");
			printf("\nExecute seu Comando:\n");

			printf("\nSeu comando foi: ");
			printf("%s",msg);
			printf("\n");
		
		//executa o comando no sistema
			system(msg);
		
		//libera os recursos para outra aplicação
			pthread_mutex_unlock(&mutex);
			printf("\n");
		
			break;
		
		default:

			pthread_mutex_lock(&mutex);
			//loca os recursos para uso exclusivo do do programa
			system(&cbsh);
			//chama o arquivo em bash para executar o comando cd
			pthread_mutex_unlock(&mutex);
			//libera os recursos para outra aplicação
			break;
			
		}
	}

}

void texto()
{
		//texto de apresentação do sistema
		printf("Trabalho Arq_Sis_Op\n");
 		printf("Comandos executados:\n");
 		printf("1- criar (sub)diretório / mkdir -p\n");
 		printf("2- remover (sub)diretório / rm -rf\n");
 		printf("4- mostrar conteúdo do diretório / ls \n");
 		printf("5- criar arquivo / nano\n");
 		printf("6- remover arquivo / rm\n");
 		printf("7- escrever um sequência de caracteres em um arquivo / vim \n");
 		printf("8- mostrar conteúdo do arquivo / more\n\n");
}