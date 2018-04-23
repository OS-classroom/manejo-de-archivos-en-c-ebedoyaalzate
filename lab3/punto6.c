#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  pid_t pid_h;
  pid_t pid_n;
  pid_h = fork();
  if(pid_h == 0) {
    pid_n = fork();
    if(pid_n==0) {
      printf("!"); //nieto      
    }else printf("Mundo");    //hijo  
    }else printf("Hola ");   //padre
  return 0;
}