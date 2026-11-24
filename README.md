# PortScope

Um scanner de portas TCP leve, desenvolvido em C.

## Instalação

### Windows

Compile utilizando GCC (MinGW):

    gcc main.c -o scanner.exe -lws2_32

## Utilização

### IPv4

    .\scanner.exe <ENDEREÇO_IP>

Exemplo:

    .\scanner.exe 127.0.0.1

## Funcionalidades

- Varredura de portas TCP
- Suporte a IPv4
- Desenvolvido em C
- Compatível com Windows

## License

This project is licensed under the MIT License.
