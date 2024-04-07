// cppserver made by nx86
// Main features to be added sometime:
// * Server which can receive data and respond to that data(POST etc.)
// * Separate client exe which can communicate over local network. 

#include "common.h"


int main (int argc, char *argv[])
{
    int server_socket = socket(AF_INET, SOCK_STREAM , 0);
   
    sockaddr_in server_address;
        server_address.sin_port = htons(PORT);
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_family = AF_INET;

    socklen_t client_addr_size;

    if (server_socket == -1) {
        std::cout << "Error creating socket. \n";
        return 1;
    }

    int binder = bind(server_socket,(struct sockaddr*)&server_address, sizeof(server_address));
    if (binder == 0) {
        std::cout << "Successfully binded on socket. \n";
    }
    else if (binder == -1){
        std::cout << "Binding failed. \n";
        close(server_socket);
        return 1;
    }
    int listener = listen(server_socket, BACKLOG);
        
        if (listener == 0) {
            std::cout << "Listening for connections on port: " << PORT << std::endl;
           //loop for client messages 
                
            int client_socket = accept(server_socket, (struct sockaddr *)&server_address, &client_addr_size);
            if (client_socket == 1) {
                std::cout << "Client connected\n";
            } 
            while(1){
                char *buffer= new char[BUFSIZE];
                int rec = recv(client_socket, buffer, sizeof(buffer), 0); 
                std::cout << "Message from client: "<< buffer << std::endl;
                if (rec == 0){; // recv() has to have zero value returned to stop
                    std::cout << "Client disconnected.\n";
                    close(server_socket);
                    return 0;
                }
                } 
            }
        else if ( listener || binder  == -1) {
            std::cout << "Error in listening. \n";
            close(server_socket);
        }
   

    return 0;
}
