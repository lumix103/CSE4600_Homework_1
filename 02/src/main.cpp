#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    cout << "Running ps with excelp\n";
    execl ("ps", "ps", "-ax", (char*)NULL);
    cout << "The program is exiting!\n";
    return 0;
}