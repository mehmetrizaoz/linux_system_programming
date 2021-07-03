#include <stdio.h>
#include <unistd.h>

int main(){
    printf("My PID is: %ld\n", (long)getpid());
    printf("My PPID is: %ld\n", (long)getppid());

    printf("My Real user-ID is: %ld\n", (long)getuid());
    printf("My Effective user-ID is: %ld\n", (long)geteuid());

    printf("My Real group-ID is: %ld\n", (long)getgid());
    printf("My Effective group-ID is: %ld\n", (long)getegid());

    return 0;
}