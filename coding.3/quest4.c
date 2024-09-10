#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc,char *argv[]) {
    int rc = fork();
    if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    char *myargs[2];
    myargs[0] = strdup("ls");
    myargs[1] = NULL;
    execvp(myargs[0], myargs);
  } else {
    wait(NULL);
  }
  return 0;
}
/*
Remi White
Probably because each one can do certain things based on the type of new program you are going to run or to take in different types of arguments.
*/