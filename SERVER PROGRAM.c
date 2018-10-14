
#include <netinet/in.h> 
#include <string.h> 
#include <sys/socket.h>
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h>

#define PORT 8080 
int main(int Val, char const *Val[]) 
{ 
    int READVALUE,SERVER, NEW; 
    int SELECT = 1; 
    struct sockaddr_in address; 
    
    int ADD = sizeof(address); 
    char buffer[1024] = {0}; 
    char *hello = "Hello from the other side"; 
       
    if ((SERVER = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    if (setsockopt(SERVER, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &SELECT, sizeof(SELECT))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
     if ((NEW = accept(SERVER, (struct sockaddr *)&address,(socklen_t*)&ADD))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(SERVER, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }
    if (bind(SERVER, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
   
    READVALUE = read( NEW, buffer, 1024); 
    printf("%s\n",buffer ); 
    send(NEW , hello , strlen(hello) , 0 ); 
    printf("SENT!!!"); 
    return 0; 
}
