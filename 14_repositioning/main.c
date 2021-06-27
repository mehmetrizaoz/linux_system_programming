#include <stdlib.h>
#include <stdio.h>

void display(FILE* fp){
   char ch;
   while((ch = fgetc(fp))!= EOF){
      fputc(ch, stdout);
   }
   printf("\n");   
}

int main(){
   FILE* fp = fopen("seekfile.txt", "r+");
   if (fp == NULL){
      printf("Error in opening file\n");
      exit(1);
   }

   display(fp);   
   printf("pos: %d\n",ftell(fp));
   
   rewind(fp);
   printf("pos: %d\n",ftell(fp));
   display(fp);

   int posn=5;
   fseek(fp,5,SEEK_SET);
   printf("pos: %d\n",ftell(fp));
   fputc('z',fp);  
   display(fp);

   rewind(fp);
   display(fp);
          
   fseek(fp,5,SEEK_END);
   fputs("mehmet",fp);
   rewind(fp);  
   display(fp);  

   return 0;
}
