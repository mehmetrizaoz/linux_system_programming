#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
	// ftok to generate unique key
	key_t key = ftok("shmfile",65);

	// shmget returns an identifier in shmid
	int shmid = shmget(key,1024,0666|IPC_CREAT);

   while(1){	   
      // shmat to attach to shared memory
	   char *str = (char*) shmat(shmid,(void*)0,0);
	   printf("Data read from memory: %s\n",str);

      if(strcmp(str, "end") == 0)
         break;	

	   //detach from shared memory
	   shmdt(str);
      sleep(3);
   }
	
	// destroy the shared memory
	shmctl(shmid,IPC_RMID,NULL);
	
	return 0;
}
