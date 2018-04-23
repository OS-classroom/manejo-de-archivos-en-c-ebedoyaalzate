#include <stdio.h>
#include <error.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int num, int i, int j);

int main(){
        int i, j, p1, p2;
        for(j=1;j<=2;j++){
                if(j==1){
                        if((p1=fork())==0){
                                i = factorial(10, 10, j);
                        }
                } else{
                        if((p2=fork())==0 && (p1==fork())!=0){
                                i = factorial(10, 10, j);
                        }
                }
        }
        i=i+1;
        wait(&p1);
        wait(&p2);
}

int factorial(int num, int i, int j){
        if (num==0){
                return 1;
        } else{
                num=num*factorial(num-1, i-1, j);
                printf("HIJO %d: fact(%d)=%d\n",j, i, num);
                return num;
        }
}
