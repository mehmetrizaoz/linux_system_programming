#include <sys/types.h>
#include <linux/unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int thread_no = 0;
void * f1(void * arg);

int main(int argc, char* argv[]){
   char* msg[] = {"Thread1", "Thread2", "Thread3", "Thread4", "Thread5"};
   int ctr = 5;
   
   pthread_t* tid =  (pthread_t*)malloc(sizeof(pthread_t)*ctr);

   for(int i=0;i<ctr;i++)
      pthread_create(&tid[i], NULL, f1, (void*)msg[i]);
   for(int j=0;j<ctr;j++)
      pthread_join(tid[j], NULL);

   printf("main(): Reporting that all child threads have terminated\n");
   exit(0);
}

void * f1(void * arg){
   int thread_id = thread_no; 
   thread_no++;
   printf("I am child %s\n", (char*)arg);
   fprintf(stderr, "I am child thread number %d \n", thread_id);
   pthread_exit(NULL);
}
