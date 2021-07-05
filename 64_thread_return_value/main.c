#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void* f1(void *);

int main(int argc, char* argv[]){
   if (argc != 3){
      printf("Invalid arguments. Pl enter two integers\n");
      exit(1);
   }
   int num1 = atoi(argv[1]);
   int num2 = atoi(argv[2]);
   pthread_t tid1, tid2;
   pthread_create(&tid1, NULL, f1, (void*)&num1);
   pthread_create(&tid2, NULL, f1, (void*)&num2);
   void* rv1, *rv2;
   pthread_join(tid1, &rv1);
   pthread_join(tid2, &rv2);
   long prime1 = *(long*)rv1;
   long prime2 = *(long*)rv2;
   printf("\nThe %dth prime number as returned by child thread is: %ld\n",num1,prime1);
   printf("\nThe %dth prime number as returned by child thread is: %ld\n",num2,prime2);
   return 0;
}

void * f1(void * args){
   int n = *((int*)args);
   long *candidate = (long*)malloc(sizeof(long));
   *candidate = n * 2;
   pthread_exit((void*)(candidate));
}

