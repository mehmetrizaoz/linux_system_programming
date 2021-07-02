#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;

int main(){
   printf("Directory scan of /home/user: \n");
   chdir("/home/user");
   DIR* dp = opendir(".");
   
   errno = 0;
   struct dirent* entry;

   while(1){
      entry = readdir(dp);
      if(entry == NULL && errno != 0){
         perror("readdir");
         return errno;
      }
      if(entry == NULL && errno == 0){
         printf("\nEnd of directory\n");
         return 0;
      }
      printf("%s\t",entry->d_name);
   }

   closedir(dp);
   return 0;
}
