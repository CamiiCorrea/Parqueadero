#include "placas.h"
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    connect(sock, (sockaddr*)&server, sizeof(server));

    while (true) {
        std::string placa = generarPlaca();
        std::string mensaje = placa + " | " + horaActual();
        send(sock, mensaje.c_str(), mensaje.size(), 0);
        std::cout << "Enviado: " << mensaje << std::endl;
        Sleep(2000); // cada 2 segundos
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
