# EASY SOCKET
Just to train c++. i built a lib for socket abstraction.
i didn't finish the server side.

Example code
```cpp
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

```
just it.
