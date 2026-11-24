#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    WSADATA wsa;

    SOCKET meusocket;
    int conecta;
    int port = 80;

    int inicio = 1;
    int final = 65535;

    char *destino;

    struct sockaddr_in alvo;

    if (argc < 2) {
        printf("Uso: scanner.exe <IP>\n");
        return 1;
    }

    destino = argv[1];

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Erro ao iniciar Winsock.\n");
        return 1;
    }

    alvo.sin_family = AF_INET;

    if (InetPtonA(AF_INET, destino, &alvo.sin_addr) != 1) {
        printf("Endereco IP invalido.\n");
        WSACleanup();
        return 1;
    }

    for (port = inicio; port <= final; port++)
    {
        meusocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (meusocket == INVALID_SOCKET) {
            printf("Erro ao criar socket: %d\n", WSAGetLastError());
            break;
        }

        alvo.sin_port = htons((u_short)port);

        conecta = connect(
            meusocket,
            (struct sockaddr *)&alvo,
            sizeof(alvo)
        );

        if (conecta == 0) {
            printf("===================================== \n");
            printf("Porta %d - status [ABERTA]\n", port);
            printf("===================================== \n");
        }else{
            printf("=====================================\n");
            printf("Porta %d - status [FECHADA] \n", port);
            printf("===================================== \n");
        }
        

        closesocket(meusocket);
    }

    WSACleanup();

    return 0;
}
