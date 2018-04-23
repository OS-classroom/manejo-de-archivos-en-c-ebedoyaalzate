#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  pid_t pid_h2, pid_h3, pid_h4, pid_h5; //procesos
  int status;
  //PROCESO 2
  pid_h2 = fork();
  if(pid_h2 == 0 ) {
      printf("El proceso 2 ha sido creado satisfactoriamente, con PID %d y padre %d\n", getpid(), getppid());
      exit(0);      
    }    
    //proceso 3
  pid_h3 = fork();
  if(pid_h3 == 0) {
      printf("El proceso 3 ha sido creado satisfactoriamente, con PID %d y padre %d\n", getpid(), getppid());

      pid_h4 = fork();
      if( pid_h4 == 0 ) {
       printf("El proceso 4 ha sido creado satisfactoriamente, con PID %d y padre %d\n", getpid(), getppid());
       exit(0);            
      }

      pid_h5 = fork();
      if( pid_h5 == 0 ) {      
        printf("El proceso 5 ha sido creado satisfactoriamente, con PID %d y padre %d\n", getpid(), getppid());
        sleep(5);
        printf("...ARBOL DE PROCESOS...\n");
        system("pstree -p"); //El arbol de procesos con sus PID 
        exit(0);            
      }
      exit(0);
      //proceso 1, padre
  }else {
      wait(&status);
      wait(&status);
      wait(&status);      
      printf("El proceso 1 ha sido creado satisfactoriamente, con PID %d y padre %d\n", getpid(), getppid());
      //exit(0);            
    }      
  return 0;
}