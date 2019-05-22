#ifndef BIBLIOTECAS_H   // Guardas de cabeçalho, impedem inclusões cíclicas
    //Bibliotecas de apoio para o codigo
    #include <stdio.h>
    #include <string.h>         //strlen
    #include <stdlib.h>         //strlen
    #include <unistd.h>         //write
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>      //inet_addr
    #include <netinet/in.h>
    #include <netdb.h>
    #include <pthread.h>        //for threading , link with lpthread

#define BIBLIOTECAS_H
#endif