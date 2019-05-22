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
        perror("Error: Conexão falhou");
        return 1;
    }
    puts("Conexão com sucesso");
     
    //Aguarda conexão
    listen(socket_desc , 10);       //Numero maximo de conexões    
    puts("Esperando por entradas das conexões");
    c = sizeof(struct sockaddr_in);
	pthread_t thread_id;
	
    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Conexão foi aceita!!");
        if(pthread_create(&thread_id, NULL,  conecLeitor, (void*) &client_sock) < 0)
        {
            perror("Não foi possível criar a thread");
            return 1;
        }
    }
	if (client_sock < 0)
    {
        perror("Falhou em se conectar!!");
        return 1;
    }
     
    return 0;
}

//Função para cada cliente
void *conecLeitor(void *socket_desc)
{

    pthread_mutex_t mutex;

    int sock = *(int*)socket_desc;
    int read_size;
	int read_size_2;
	int comandoUser[1];
    char *message , client_message[2000];
    char cbsh = ". ./bashcd.sh";
	char *swtcError, *cmdApr;
	swtcError = malloc(sizeof(char)*500);
    cmdApr = malloc(sizeof(char)*500);
    //Texto de apresentação do sistema enviado ao cliente
    char *funcOp;
    funcOp = malloc(sizeof(char)*500);
		funcOp = "Trabalho Arq_Sis_Op\n Comandos executados:\n 1- criar (sub)diretório / mkdir -p\n 2- remover (sub)diretório / rm -rf\n 4- mostrar conteúdo do diretório / ls \n 5- criar arquivo / nano\n 6- remover arquivo / rm\n 7- escrever um sequência de caracteres em um arquivo / vim \n8- mostrar conteúdo do arquivo / more\n\n";
    write(sock , funcOp , strlen(funcOp));

    //Para receber mensagens dos clientes
    while((read_size_2 = recv(sock , comandoUser , 1 , 0)) > 0 )
    {
		switch (comandoUser[0])
		{
			case 1:
				//1- criar (sub)diretório / mkdir -p\n
                pthread_mutex_lock(&mutex);
                while(read_size = recv(sock , comandoUser , 1 , 0) > 0 )
                {           
                    client_message[read_size] = '\0';
                }
				system(client_message);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);

                pthread_mutex_unlock(&mutex);
				break;
			case 2:
				//2- remover (sub)diretório / rm -rf\n
                pthread_mutex_lock(&mutex);
                while(read_size = recv(sock , comandoUser , 1 , 0) > 0 )
                {           
                    client_message[read_size] = '\0';
                }
				system(client_message);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);

                pthread_mutex_unlock(&mutex);
				break;

			case 3:
				//3- entrar em (sub)diretório / cd\n
                pthread_mutex_lock(&mutex);
				//Chama o arquivo em bash para executar o comando cd
				system(&cbsh);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);
                pthread_mutex_unlock(&mutex);
				break;

			case 4:
				//4- mostrar conteúdo do diretório / ls \n"
                pthread_mutex_lock(&mutex);
                while(read_size = recv(sock , comandoUser , 1 , 0) > 0 )
                {           
                    client_message[read_size] = '\0';
                }
				system(client_message);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);

                pthread_mutex_unlock(&mutex);
				break;

			case 5:
				//5- criar arquivo / nano\n
                pthread_mutex_lock(&mutex);
                while(read_size = recv(sock , comandoUser , 1 , 0) > 0 )
                {           
                    client_message[read_size] = '\0';
                }
				system(client_message);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);

                pthread_mutex_unlock(&mutex);
				break;

			case 6:
				//6- remover arquivo / rm\n
                pthread_mutex_lock(&mutex);
                while(read_size = recv(sock , comandoUser , 1 , 0) > 0 )
                {           
                    client_message[read_size] = '\0';
                }
				system(client_message);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);

                pthread_mutex_unlock(&mutex);
				break;

			case 7:
				//7- escrever um sequência de caracteres em um arquivo / \n
                pthread_mutex_lock(&mutex);
                while(read_size = recv(sock , comandoUser , 1 , 0) > 0 )
                {           
                    client_message[read_size] = '\0';
                }
				system(client_message);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);

                pthread_mutex_unlock(&mutex);
				break;
			
			case 8:
				//8- mostrar conteúdo do arquivo / more\n\n
                pthread_mutex_lock(&mutex);
                while(read_size = recv(sock , comandoUser , 1 , 0) > 0 )
                {           
                    client_message[read_size] = '\0';
                }
				system(client_message);
                //Envia confirmação
                cmdApr = "\nComando realizado com sucesso\n";
                write(sock , cmdApr , strlen(client_message));
                //Limpa o buffer
                memset(client_message, 0, 2000);

                pthread_mutex_unlock(&mutex);
				break;

			default:
				swtcError = "Comando invalido\n";
				write(sock , swtcError , strlen(swtcError));
				break;
		}
		//Envia mensagem para o cliente
      	write(sock , client_message , strlen(client_message));
		
		//Limpa o buffer da mensagem
		memset(client_message, 0, 2000);
    }
     
    if(read_size == 0)
    {
        puts("Cliente foi desconectado");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("receber do cliente falhou");
    }
         
    return 0;
} 