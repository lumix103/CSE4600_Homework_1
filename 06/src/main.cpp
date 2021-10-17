#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void alarm_off(int sig) {
    cout << "Alarm has gone off" << endl;
}

int main() {
    int pid;
    cout << "Alarm testing!" << endl;
    if((pid = fork()) == 0) {
        sleep(5);
        kill(getppid(), SIGALRM);
        return 1;
    }
    cout << "Waiting for alarm to go off!" << endl;
    (void) signal (SIGALRM, alarm_off);
    pause();
    cout<< "Done!" << endl;
    return 1;
}
