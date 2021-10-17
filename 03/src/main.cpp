#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    pid_t pid;
    char* message;
    int n;
    cout << "fork program starting\n";
    pid = fork();
    switch (pid)
    {
    case -1:
        cout <<"Fork failure!\n";
        return 1;
        break;
    case 0:
        message = "This is the child\n";
        n = 5;
        break;
    default:
        message = "This is the parent\n";
        n = 3;
        break;
    }
    for (int i = 0; i < n; ++i) {
        cout << message;
        sleep(1);
    }
    return 0;
}