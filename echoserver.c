#include <stdio.h> /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h> /* for sockaddr_in and inet_addr() */
#include <stdlib.h> /* for atoi() and exit() */
#include <string.h> 
#include <unistd.h> /* for close() */
#include <netdb.h> /* Transform the ip address string to real uint_32 */

int main()
{ 
   char str[100];
    int socket_desc, comm_fd;
   struct sockaddr_in servaddr;

 //Create Socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));

//Prepare the sockaddr_in structure 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
 //Bind
    bind(socket_desc, (struct sockaddr *) &servaddr, sizeof(servaddr));
//Listen
    listen(socket_desc, 10);
    printf("\n\n -----Server is Running right Now-----\n\n");

//Accept incoming connection

    comm_fd = accept(socket_desc, (struct sockaddr*) NULL, NULL);
    printf("\n\nReceived Client Request:) \n\n");

    while(1)
    { 

        bzero( str, 100);
        read(comm_fd,str,100);
        printf("Echoing back - %s",str);
        write(comm_fd, str, strlen(str)+1);
    }
}

