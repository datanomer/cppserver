#include "common.h"
//client for interacting with server

int main()
{
    int clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    const void *buf[BUFSIZE];
    if (clientsocket == -1) {
        std::cout << "Socket creation failed. \n";
        close(clientsocket);
        return 1;
    }
    else {
        std::cout << "Socket created. \n"; 
    }

    sockaddr_in client_address;
        client_address.sin_port = htons(PORT);
        client_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        client_address.sin_family = AF_INET;

   int server_socket = connect(clientsocket, (struct sockaddr*)&client_address, sizeof(client_address)); 
   if (server_socket == 0) {  
       while(1) {
            char msg[BUFSIZE] = {0};
            std::cin >> msg;
            int server_socket = connect(clientsocket, (struct sockaddr*)&client_address, sizeof(client_address)); 
            send(clientsocket, msg, strlen(msg), 0);
            std::cout << "Message sent successfully\n";  
       }
        close(clientsocket);
   }
   else if(server_socket == -1){    
       std::cout << "Message failed to send. \n";
        close(clientsocket);
        return 1;
   }

   return 0;
}

