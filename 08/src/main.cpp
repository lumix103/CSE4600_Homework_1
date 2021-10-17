#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    FILE *fpi;
    char buffer[BUFSIZ+1];
    int  chars_read;
    
    fpi = popen("ps -auxw", "r");
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