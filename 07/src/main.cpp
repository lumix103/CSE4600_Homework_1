#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void alarm_off(int sig, siginfo_t* _,  void* __) {
    cout << "Alarm has gone off" << endl;
}

int main() {
    struct sigaction action;
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = alarm_off;
    int pid;
    cout << "Alarm testing!" << endl;
    pid = fork();
    if(pid == 0) {
        while(1) {
            sleep(5);
            kill(getppid(), SIGQUIT);
            return 1;
        }
    }
    cout << "Waiting for alarm to go off!" << endl;
    sigaction(SIGQUIT, &action, NULL);
    pause();
    cout<< "Done!" << endl;
    return 1;
}
