#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>

int main(){
//get the scheduling policy of the currently running process   
   int s_policy = sched_getscheduler(getpid());
   printf("Scheduling policy of the current process = %d\n", s_policy);

//get the time slice
   struct timespec tp;
   int rv = sched_rr_get_interval(getpid(), &tp);
   if(rv == -1){
      printf("Error in getting the time slice\n");
      exit(1);
   }
   printf("Time Slice is %ld sec and %ld nanosecs \n", tp.tv_sec, tp.tv_nsec);

   int min = sched_get_priority_min(SCHED_RR);
   printf("Minimum priority value for SCHED_RR = %d\n", min);
   int max = sched_get_priority_max(SCHED_RR);
   printf("Maximum priority value for SCHED_RR = %d\n", max);
   
   min = sched_get_priority_min(SCHED_FIFO);
   printf("Minimum priority value for SCHED_FIFO = %d\n", min);
   max = sched_get_priority_max(SCHED_FIFO);
   printf("Maximum priority value for SCHED_FIFO = %d\n", max);

   min = sched_get_priority_min(SCHED_OTHER);
   printf("Minimum priority value for SCHED_OTHER = %d\n", min);
   max = sched_get_priority_max(SCHED_OTHER);
   printf("Maximum priority value for SCHED_OTHER = %d\n", max);
   return 0;
}