#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
        char entrada[50];
        char programa[52]="./";
        int p1;
        printf("Ingrese el nombre del programa que desea ejecutar:\n");
        scanf("%s", entrada);
        strcat(programa, entrada);
        if((p1=fork())==0){
                system(programa);
        } else if((p1=fork())<0){
                perror("error al crear el fork()\n");
        } else{
                wait(&p1);
                printf("DONE!\n");
        }
        sleep(2);
}
