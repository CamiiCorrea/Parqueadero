#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET server = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(server, (sockaddr*)&addr, sizeof(addr));
    listen(server, 3);

    SOCKET client;
    sockaddr_in clientAddr;
    int c = sizeof(clientAddr);

    client = accept(server, (sockaddr*)&clientAddr, &c);

    char buffer[1024];
    while (true) {
        int recv_size = recv(client, buffer, sizeof(buffer), 0);
        if (recv_size > 0) {
            buffer[recv_size] = '\0';
            std::cout << "Recibido: " << buffer << std::endl;
        }
    }

    closesocket(server);
    WSACleanup();
    return 0;
}
