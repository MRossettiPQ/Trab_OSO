//TESTE DE CLIENTE
/*
    Para compilar no terminal use:
    gcc cliente.c -lpthread -o cliente
    Cliente Simples Para Servidor com Thread
*/
#include "bibliotecas.h"

//Declaração função

int main()
	{
	 	int sock_conn, val;
		struct sockaddr_in client_addr;
		char fila[500], fila2[5000], aux = 0;
		sock_conn = socket(AF_INET, SOCK_STREAM, 0);

		client_addr.sin_family = AF_INET;
		client_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
		client_addr.sin_port = htons(9002);

		if(connect(sock_conn, (struct sockaddr*)&client_addr, sizeof(client_addr)) == 0)
			printf("Conexão estabalecida com o servidor !! \n");
		else
			printf("Falha ao conectar no servidor !\n");

		read(sock_conn,fila,499);
		printf("Mensagem do servidor: %s\n\n",fila);
		bzero(fila,500);

		while(1) 
		{
			printf("Qual comando você deseja: ");
			bzero(fila,500);
			scanf("%s", fila);
			aux = fila[0];
			write(sock_conn, fila, strlen(fila));
			bzero(fila,500);

			if(aux == '4')
			{
				read(sock_conn,fila,499);
				printf("Arquivos da pasta: \n%s\n\n",fila);
				bzero(fila,499);
			}
			else if (aux == '5')
			{
				printf("Digite o nome do arquivo: ");
				scanf("%s", fila);
				write(sock_conn,fila,strlen(fila));
				bzero(fila,500);
			}
			else if (aux == '7')
			{
				printf("Digite o nome do arquivo: ");
				scanf("%s", fila);
				write(sock_conn,fila,strlen(fila));
				bzero(fila,500);

				printf("Digite o texto: ");
				scanf("%s", fila2);
				write(sock_conn,fila2,strlen(fila2));
				bzero(fila2,5000);
			}
			else if (aux == '8')
			{	
				printf("Digite o nome do arquivo: ");
				scanf("%s", fila);
				write(sock_conn,fila,strlen(fila));
				bzero(fila,500);

				read(sock_conn,fila,499);
				printf("Conteudo do arquivo: \n%s\n\n",fila);
				bzero(fila,499);
			}
			else
			{
				printf("Digite o comando: ");
				scanf("%s", fila);
				write(sock_conn,fila,strlen(fila));
				bzero(fila,500);
			}





			read(sock_conn,fila,499);
			printf("Mensagem do servidor : %s\n\n",fila);
			
	
		}
	//close(sock_conn);
	return 0;	
}