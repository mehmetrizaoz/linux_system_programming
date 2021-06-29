#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void){    
   int fdOne, fdTwo, fdThree;   
   fdOne = open("abc.txt", O_CREAT | O_TRUNC);

   if(fdOne < 0){
      printf("Error opening / creating test.txt. ");
      if(errno==EACCES){
         printf("Error #%d (EACCES): Permission denied.\n", EACCES);
         exit(EXIT_FAILURE);
      }
   } else {
      printf("test.txt created / opened ");
      printf("with file descriptor %d.\n", fdOne);
   }

   //lets use the fcntl() function to copy the 
   //file descriptor
   if((fdTwo = fcntl(fdOne, F_DUPFD, 0))<0){
      printf("Error duplicating file descriptor.\n");
      exit(EXIT_FAILURE);
   } else {
      printf("File descriptor duplicated. ");
      printf("New file descriptor is %d.\n", fdTwo);
   }

   //set the file descriptor to be a higher number;
   if((fdThree = fcntl(fdOne, F_DUPFD, 11))<0){
      printf("Error duplicating file descriptor.\n");
      exit(EXIT_FAILURE);
   } else {
      printf("File descriptor duplicated. ");
      printf("New file descriptor is %d.\n", fdThree);
   }

   close(fdOne);
   close(fdTwo);
   close(fdThree);

   return 0;
}


