#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   char buff[256];
   int n1 = read (STDIN_FILENO, buff, 255);
   if (n1 == -1){
      perror("Error in reading file\n");
      exit(1);
   }

   int n2 = write(STDOUT_FILENO, buff, n1); 
   if(n2 == -1){
      perror("Error in writing file\n");
      exit(1);
   }

   return 0;
}

