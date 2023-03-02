#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
    int sockDescript;
    struct sockaddr_in receiverAddr, senderAddr;
    char receiverMsg[1024], senderMsg[1024];
    int senderStructLength = sizeof(senderAddr);
    char *ip = "0.0.0.0";
    memset(receiverMsg, '\0', sizeof(receiverMsg));
    memset(senderMsg, '\0', sizeof(senderMsg));

    sockDescript = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockDescript < 0){
        fprintf(stderr, "ERROR CREATING SOCKET\n");
        return -1;
    }
    
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(26788);
    receiverAddr.sin_addr.s_addr = inet_addr(ip);
    
    if(bind(sockDescript, (struct sockaddr*)&receiverAddr, sizeof(receiverAddr)) < 0){
        fprintf(stderr, "ERROR BINDING TO PORT\n");
        return -1;
    }
    printf("Waiting for messages...\n");

    while (1){
        int bytes = recvfrom(sockDescript, senderMsg, 10, 0, (struct sockaddr*)&senderAddr, (socklen_t*)&senderStructLength);

        if(bytes != 10){
            fprintf(stderr, "Error receiving all bytes.\n");
        }
        printf("Received message from IP: %s and port: %i\n", inet_ntoa(senderAddr.sin_addr), ntohs(senderAddr.sin_port));
    
        printf("%s\n", senderMsg);
        bzero(senderMsg, 10);
    }

    shutdown(sockDescript, 2);
    return 0;
}
