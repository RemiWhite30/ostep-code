#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello\n");
  } else {
    wait(NULL);
    printf("goodbye\n");
  }
  return 0;
}
/*
Remi White
I am not aware of a way to ensure the child process runs first without calling wait.
*/
