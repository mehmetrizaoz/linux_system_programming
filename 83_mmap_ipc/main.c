#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
//open a file
   int fd = open("file.txt", O_RDWR);
//get attributes of the file
   struct stat sbuff;
   fstat(fd, &sbuff);
   int fsize = sbuff.st_size;
//memory map the file
   char* filedata = mmap(NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
   
//create a child process
   pid_t cpid = fork();
   if(cpid==0){
      printf("Child access memory mapped file: %s\n", filedata);
      filedata[0] = 'k';
      munmap(filedata, fsize);
      close(fd);
      exit(0);
   }
   else{
      waitpid(cpid, NULL,0);
      printf("Parent access memory mapped file: %s\n", filedata);
      munmap(filedata, fsize);
      close(fd);
      exit(0);
   }
   return 0;
}