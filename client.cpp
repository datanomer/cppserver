#include "common.h"
// Client connection process to listening server
// X. Client socket creation
// X. Defining server addresse
// 3. connecting to server socket
// 4. sending data to server
// 5. Closing the client socket


int main()
{
    int clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    const void *buf[BUFSIZE];
    sockaddr_in client_address;
        client_address.sin_port = htons(PORT);
        client_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        client_address.sin_family = AF_INET;

   int server_socket = connect(clientsocket, (struct sockaddr*)&client_address, sizeof(client_address)); 
   if (server_socket == 0) {
        const char* msg = "fuckni";
        send(clientsocket, msg, strlen(msg), 0);
        std::cout << "Message sent successfully\n";
   }
   else if(server_socket == -1){    
       std::cout << "Message failed to send. \n";
        close(clientsocket);
        return 1;
   }

   return 0;
}

