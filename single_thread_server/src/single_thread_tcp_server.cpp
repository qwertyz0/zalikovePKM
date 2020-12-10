#include "single_thread_tcp_server.h"
using namespace std;

void handle_connection(SOCKET socket, sockaddr_in* addr) {
    char* str_in_addr = inet_ntoa(addr->sin_addr);
    printf("[%s]>>%s\n", str_in_addr, "Establish new connection");
    while (true) {
        /*char buffer[256] = "";
        int rc = recv(socket, buffer, sizeof(buffer), 0);
        if (rc > 0) {
            printf("[%s]:%s\n", str_in_addr, buffer);
        }
        else {
            break;
        }*/

        const int STRLEN = 256;
        char buffer[STRLEN];
        //scanf.getline(s, STRLEN);
        int rc = recv(socket, buffer, sizeof(buffer), 0);

        size_t maxlen = 0;
        char* maxidx = nullptr;

        int max = 0;
        int temp = 0;
        int startOfword = 0;
        int endofword = 0;
        for (int i = 0; i < sizeof(buffer); i++) {
            if (buffer[i] != ' ') {
                temp++;
                
            }
            else {
                if (temp > max) {
                    max = temp;
                    maxlen = max;
                    endofword = i;
                    startOfword = i - max;
                }
                temp = 0;
            }
        }


        //const int  len = max;
        //char s[len];

        char* s = "";
        temp = 0;

        for (int i = startOfword; i < endofword; i++) {
            s[temp] = buffer[i];
            temp++;

        }
        printf("%s",s);


 /*       for (char* c = buffer; *c;) {
            while (*c == ' ') ++c;
            if (*c == 0) break;
            char* begin = c;
            while (*c && *c != ' ')++c;

            if (maxlen < (c - begin)) {
                maxlen = c - begin;
                maxidx = begin;
            
            }
        
        }
        if (maxlen == 0) {
            printf("Empty ");
            
        
        }
        else {
            *(maxidx + maxlen) = 0;
            printf(maxidx, str_in_addr, buffer);
        }*/


    }
    close_socket(socket);
    printf("[%s]>>%s", str_in_addr, "Close incomming connection");
}