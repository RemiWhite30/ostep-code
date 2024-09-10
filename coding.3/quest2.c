#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  int fd = open("./tempfile.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Child\n");
    write(fd, "I am the child\n", 16);
  } else {
    printf("Parent\n");
    write(fd, "I am the parent\n", 17);
  }
  return 0;
}
/*
Remi White
Yes, they both can access the file descriptor returned.
One of them writes before the other one, but it is undeterministic unless we use wait().
*/
