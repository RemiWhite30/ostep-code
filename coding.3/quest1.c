#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]) {
  int x = 100;
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Child Process\n");
    printf("Value of x: %d\n", x);
    x = 105;
    printf("New value of x: %d\n", x);
  } else {
    printf("Parent Process\n");
    printf("Value of x: %d\n", x);
    x = 110;
    printf("New value of x: %d\n", x);
  }
  return 0;
}
/*
Remi White
The value of the variable in the child process should be 100 since it is just a copy of the parent process.
When each one change the value of x it only changes it locally inside of each process. 
The child changing the value doesn't change it for the parent and vice versa.
*/
