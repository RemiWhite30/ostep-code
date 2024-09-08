#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Child\n");
  } else {
    waitpid(rc, &argc, 0);
    printf("Parent\n");
  }
  return 0;
}
/*
Remi White
waitpid() would be useful when we want to wait on a specific child process instead of having to wait all of the child processes to finish. 
*/
