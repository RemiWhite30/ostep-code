#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  int pipefd[2];
  char buf;
  if (pipe(pipefd) < 0) {
    exit(1);
  }
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Child 1\n");
    close(pipefd[0]);
    write(pipefd[1], "Pipe Succesful\n", 15);
    close(pipefd[1]);
  } else {
    int rc1 = fork();
    if (rc1 < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc1 == 0) {
      close(pipefd[1]);
      while (read(pipefd[0], &buf, 1) > 0)
        write(STDOUT_FILENO, &buf, 1);
      write(STDOUT_FILENO, "\n", 1);
      close(pipefd[0]);
      printf("Child 2\n");
    } else {
    printf("Parent\n");
    }
  }
  return 0;
}

/*
Remi White
I used https://www.man7.org/linux/man-pages/man2/pipe.2.html for help with pipe().
*/