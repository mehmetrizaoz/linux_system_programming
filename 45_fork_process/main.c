#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int gvar=555;
int main(){
    int lvar = 54;
    int cpid, ctr=0;
    cpid = fork();

    if(cpid == 0){
        ctr = 100;
        printf("child: PID=%ld, gvar=%d, lvar=%d ctr=%d\n", (long)getpid(),gvar,lvar,ctr);
    }
    else{
        printf("parent: PID=%ld, gvar=%d, lvar=%d ctr=%d\n", (long)getpid(),gvar,lvar,ctr);
    }
    
    printf("who is here.\n");
    return 0;
}