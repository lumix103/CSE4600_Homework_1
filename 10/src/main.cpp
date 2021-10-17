#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int nbytes;
  int fd[2];		
  const char s[] = "CSUSB";
  char buffer[BUFSIZ+1];

  memset (buffer, 0, sizeof(buffer));

  if (pipe(fd) == 0) {
    nbytes = write(fd[1], s, strlen(s));
    cout << "Sent " << nbytes << " bytes to pipe." << endl;
    nbytes = read (fd[0], buffer, BUFSIZ);
    cout << "Read " << nbytes << " from pipe: " << buffer << endl;
    return 0;
  }
  return 1;
}
