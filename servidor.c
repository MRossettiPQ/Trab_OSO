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

    //Conectar com servidor
    if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("Error: Conexão falhou");
        return 1;
    }
    puts("Conexão com sucesso");
     
    //Aguarda conexão
    listen(socket_desc , 10);       //Numero maximo de conexões    
    puts("Esperando por entradas das conexões");
    c = sizeof(struct sockaddr_in);
	pthread_t thread_id;
	
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

	 char msg[499];
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