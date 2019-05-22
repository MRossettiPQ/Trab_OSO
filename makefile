all: cliente servidor
servidor : servidor.c bibliotecas.h
	gcc -o servidor.c servidor -lpthread
cliente : cliente.c bibliotecas.h
	gcc -o cliente.c cliente -lpthread