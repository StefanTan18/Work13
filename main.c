#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler( int signo ) {
  if (signo == SIGINT) {
    int fd = open("err.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
    char s[] = "Program Exited Due to SIGINT\n";
    write(fd, s, 29);
    close(fd);
    printf("\nProgram Exited Due to SIGINT\n");
    exit(0);
  }
  if (signo == SIGUSR1) {
    printf("PID of Parent Process: %d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1) {
    printf("Process' PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
    
  
