#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
using namespace std;
class Socks_cl 
{
    private:
        struct sockaddr_in client;
        socklen_t client_size = sizeof(client);
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        int port;
        char *buffer;
    public:
        Socks_cl(const char [], int);
        bool connects();
        bool sends(const char []);
        char* recvs(int);
        void closes();

};
Socks_cl::Socks_cl(const char host[], int port_in) : port(port_in){
    client.sin_family = AF_INET;
    client.sin_port = htons(port);
    inet_pton(AF_INET, host, &client.sin_addr.s_addr);
    
}
bool Socks_cl::connects() {
    int status = connect(sock, (struct sockaddr *)&client, client_size);
    if (status < 0 ) return false;
    else return true;
}
bool Socks_cl::sends(const char host[]){
    int status = send(sock, host, strlen(host), 0);
    if (status < 0) return false;
    else return true;

    
}
char* Socks_cl::recvs(int size) {
    buffer = (char*) malloc( size*sizeof(char) );
    recv(sock, buffer, sizeof(buffer), 0);
    return buffer;
}
void Socks_cl::closes(){
    close(sock);
}
