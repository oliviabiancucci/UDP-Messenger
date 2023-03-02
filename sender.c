#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char ** argv){

    if (argc != 3) {
		fprintf(stderr, "Invalid number of commands, exiting.\n");
        return -1;
	}

    int sockDescript;
    struct sockaddr_in receiverAddr;
    char receiverMsg[1024], senderMsg[1024];
    int receiverStructLength = sizeof(receiverAddr);
    memset(receiverMsg, '\0', sizeof(receiverMsg));
    memset(senderMsg, '\0', sizeof(senderMsg));
    
    sockDescript = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockDescript < 0){
        fprintf(stderr, "ERROR CREATING SOCKET\n");
        return -1;
    }
    
    receiverAddr.sin_family = AF_INET;
    receiverAddr.sin_port = htons(26788);
    receiverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    FILE* fp = fopen(argv[2], "r+");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the file.");
        return -1;
    }

    while (fread(senderMsg, sizeof(char), 10, fp) != 0){ 
        while((strlen(senderMsg)) < 10){
            strcat(senderMsg, " ");
        }

        int n = sendto(sockDescript, senderMsg, 10, 0, (struct sockaddr*)&receiverAddr, receiverStructLength); 
        if (n == -1){
            fprintf(stderr, "Error sending data to the server.");
        return -1;
        }
        
        printf("\nSent: %s", senderMsg);
        bzero(senderMsg, 10);
    }

    fclose(fp);
    shutdown(sockDescript, 2);
    return 0;
}

