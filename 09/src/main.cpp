#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    char cmd_args_buffer[BUFSIZ+1];
    for(int i = 1; i < argc; i++) {
        if (i == 1) {
            strcpy(cmd_args_buffer, argv[i]);
        } else {
            strcat(cmd_args_buffer, " ");
            strcat(cmd_args_buffer, argv[i]);
        }
    }
    FILE *fpi;
    char buffer[BUFSIZ+1];
    int  chars_read;
    
    fpi = popen(cmd_args_buffer, "r");
    if (fpi != NULL) {
        chars_read = fread(buffer,sizeof(char), BUFSIZ, fpi);
        if(chars_read > 0) {
            cout << "Output from pipe: "<< buffer << endl;
        }
        pclose(fpi);
        return 0;
    }
    return 1;
}