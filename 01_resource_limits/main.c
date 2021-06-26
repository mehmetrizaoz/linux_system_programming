#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>

extern int errno;

int main(){
   struct rlimit limit;
   
   //RLIMIT_NOFILE
   if(getrlimit(RLIMIT_NOFILE, &limit) < 0)
      fprintf(stderr, "%s\n", strerror(errno));
   else{
      printf("%s","RLIMIT_NOFILE: \t");      
      if (limit.rlim_cur == RLIM_INFINITY)
         printf(" (infinity) ");
      else
         printf(" %d ", limit.rlim_cur);

      if (limit.rlim_max == RLIM_INFINITY)
         printf(" (infinity) \n");
      else
         printf(" %d \n", limit.rlim_max);
   }
   
   //RLIMIT_DATA   
   if (getrlimit(RLIMIT_DATA, &limit) < 0)
      fprintf(stderr, "%s\n", strerror(errno));
   else{
      printf("%s","RLIMIT_DATA:\t");
      if (limit.rlim_cur == RLIM_INFINITY)
         printf(" (infinity) ");
      else
         printf("%d ", limit.rlim_cur);

      if (limit.rlim_max == RLIM_INFINITY)
         printf(" (infinity) \n");
      else
         printf("%d \n", limit.rlim_max); 
   }
   
   //RLIMIT_NPROC
   if (getrlimit(RLIMIT_NPROC, &limit) < 0)
      fprintf(stderr, "%s\n", strerror(errno));
   else{
      printf("%s","RLIMIT_NPROC:\t");
      if (limit.rlim_cur == RLIM_INFINITY)
         printf(" (infinity) ");
      else
         printf(" %d ", limit.rlim_cur);

      if (limit.rlim_max == RLIM_INFINITY)
         printf(" (infinity) \n");
      else
         printf(" %d \n", limit.rlim_max);  
   }    

   //RLIMIT_CPU
   if (getrlimit(RLIMIT_CPU, &limit) < 0)
      fprintf(stderr, "%s\n", strerror(errno));
   else{
      printf("%s","RLIMIT_CPU:\t");
      if (limit.rlim_cur == RLIM_INFINITY)
	 printf(" (infinity) ");
      else
         printf("%d ", limit.rlim_cur);

      if (limit.rlim_max == RLIM_INFINITY)
         printf(" (infinity) \n");
      else
         printf("%d \n", limit.rlim_max);
   }
      
   return 0;        
}	


