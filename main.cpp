// cppserver made by nx86
// Main features to be added:
// * Server which can receive data and respond to that data(POST etc.)
// * Separate client exe which can communicate over local network. 

// Server connection handling process:
// 1. Create socket 
// 2. Define server address 
// 3. bind the listening port 
// 4. Listening for connections
// 5. Receive connection from client.cpp 
// 6. Receive data from clien.cpp 
// 7. Close connection/server socket

#include "common.h"


int main (int argc, char *argv[])
{
    int server_socket = socket(AF_INET, SOCK_STREAM , 0);
   
    sockaddr_in server_address;
        server_address.sin_port = htons(PORT);
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_family = AF_INET;

    int client_socket = accept(AF_INET, (struct sockaddr*)&server_address, sizeof(server_address));
 
    if (server_socket == -1) {
        std::cout << "Error creating socket. \n";
        return 1;
    }

    int binder = bind(server_socket,(struct sockaddr*)&server_address, sizeof(server_address));
    if (binder == 0) {
        std::cout << "Successfully binded on socket. \n";
        std::cout << "Listening for connections on port: " << PORT << std::endl;
        
        int listener = listen(server_socket, BACKLOG);

            if (listener == 0) {
                char buffer[BUFSIZE] = { 0 };
                recv(client_socket, buffer, sizeof(buffer), 0);
                std::cout << buffer << std::endl;
                close(server_socket);
                close(client_socket);
            }
            else {
                std::cout << "Error in listening. \n";
                close(server_socket);
                close(client_socket);
            }
    }
    else if(binder == -1){
        std::cout << "Binding failed. \n";
        close(server_socket);
        close(client_socket);
        return 1;
    }

    return 0;
}
