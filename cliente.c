//TESTE DE CLIENTE
/*
    Para compilar no terminal use:
    gcc cliente.c -lpthread -o cliente
    Cliente Simples Para Servidor com Thread
*/
#include "bibliotecas.h"

//Declaração função
void conexão();

int main()
	{
		int sock_conn, val;
		struct sockaddr_in client_addr;
		char fila[256];
		sock_conn = socket(AF_INET, SOCK_STREAM, 0);

		void conexão();

	while(1) 
		{
			printf("Mensagem do Servidor: ");
			bzero(fila,300);
			scanf("%s", fila);
	
			write(sock_conn,fila,strlen(fila));
			bzero(fila,300);

			read(sock_conn,fila,299);
			printf("Mensagem do servidor: %s\n\n",fila);
	
		}
	close(sock_conn);
	return 0;	
}

void conexão()
{
		client_addr.sin_family = AF_INET;
		client_addr.sin_addr.s_addr = inet_addr("192.168.0.160"); 
		client_addr.sin_port = htons(9002);

		if(connect(sock_conn, (struct sockaddr*)&client_addr, sizeof(client_addr)) == 0)
			printf("Conexão estabalecida com o servidor !! \n");
		else
			printf("Falha ao conectar no servidor !\n");

		read(sock_conn,fila,299);
		printf("Mensagem do servidor: %s\n\n",fila);
		bzero(fila,300);
}