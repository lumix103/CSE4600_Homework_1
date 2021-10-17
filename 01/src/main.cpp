#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <vector>
#include <iostream>

using namespace std;

constexpr int PROCESSES = 10;

int main(int argc, char** argv) {

    vector<int> pids;
    for(int i = 0; i < PROCESSES; i++) {
        pids.push_back(getpid());
        auto pid = fork();
        if (pid != 0) {
            cout<<"[" << i << "] " <<"Process " << pids[i] << " is my parent and I am process " << pid << ".\n";
            wait(NULL);
            return 0;
        }
    }
    return 0;
}