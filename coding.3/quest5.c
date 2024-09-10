#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0){
    
    int child_wait = wait(NULL);
    printf("Child %d\n", child_wait);
  } else {
    int rc_wait = wait(NULL);
    printf("Parent waited on %d\n", rc_wait);
  }
  return 0;
}
/*
Remi White
wait() returns the PID of the process that it waited on to run. 
If wait() is in the child process it returns -1 because there is no child process of that child to wait on. 
*/
