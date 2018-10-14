
#include <netinet/in.h> 
#include <string.h> 
#include <sys/socket.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h>
   
int main(int Val, char const *argv[]) 
{ 
     int socket1 = 0;
     struct sockaddr_in address; 
   

     int  READVALUE; 
    struct sockaddr_in serv_addr; 

    char *hello = "Hello from the other side(client)"; 
   
    char buffer[1024] = {0};
 
    if ((socket1 = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n error!! \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("Failed!! \n"); 
        return -1; 
    }

    //conversion of ip
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("INVALID"); 
        return -1; 
    } 
   
    
    send(socket1 , hello , strlen(hello) , 0 ); 
    printf("Sent!\n"); 
    valread = READVALUE( socket1 , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0; 
}
