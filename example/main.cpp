#include <iostream>
#include "clientsock.cpp"
#include <cstring>


int main() {
    Socks_cl cliente("127.0.0.1", 2222);
    cliente.connects();
    char *msg; 
    msg = cliente.recvs(1024);
    if (strcmp(msg, "Ola\n") == 0) cliente.sends("Ola amigo\n"); 
}
