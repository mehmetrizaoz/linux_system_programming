#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void displayUserIds(uid_t ruid, uid_t euid, uid_t suid){
    getresuid(&ruid, &euid, &suid);
    printf("\n\nAfter setuid(1002) the IDs are:\n");
    printf("My Real user-ID is: %ld\n", (long)ruid);
    printf("My Effective user-ID is: %ld\n", (long)euid);
    printf("My Saved Set-user-ID is: %ld\n", (long)suid);
}

void displayGroupIds(gid_t rgid, gid_t egid, gid_t sgid){
    getresgid(&rgid, &egid, &sgid);
    printf("My Real group-ID is: %ld\n", (long)rgid);
    printf("My Effective group-ID is: %ld\n", (long)egid);
    printf("My Saved Set-group-ID is: %ld\n", (long)sgid);
}

int main(){
    gid_t rgid, egid, sgid;
    displayGroupIds(rgid, egid, sgid);

    uid_t ruid, euid, suid;   
    displayUserIds(ruid, euid, suid);

    int rv = setuid(1002);
    if (rv == -1){
        printf ("Error in setting ID\n");
        exit(1);
    }
    displayUserIds(ruid, euid, suid);

    rv = setresuid(100, 2000, 3000);
    if (rv == -1){
        printf ("Error in setting ID\n");
        exit(1);
    }
    displayUserIds(ruid, euid, suid);

    return 0;
}
