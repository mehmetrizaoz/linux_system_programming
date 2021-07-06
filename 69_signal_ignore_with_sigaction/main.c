#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
 //signal(SIGINT,SIG_IGN);
 //signal(SIGFPE, SIG_IGN);
   struct sigaction newact;
   newact.sa_handler = SIG_IGN;
   newact.sa_flags = 0;
   sigemptyset(&newact.sa_mask);
   sigaction(SIGINT, &newact, NULL);
   sigaction(SIGFPE, &newact, NULL);

 while(1) {
   printf("I am in an infinite loop!\n");
   printf("You can't kill me by SIGINT <2> or SIGFPE <8>\n");
   sleep(2);
 }
 return 0;
}