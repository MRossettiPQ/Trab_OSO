all: cliente
cliente : cliente.c bibliotecas.h
	gcc cliente.c -o cliente -lpthread
