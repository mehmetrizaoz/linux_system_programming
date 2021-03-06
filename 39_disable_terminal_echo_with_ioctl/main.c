#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
int main(int argc, char *argv[]){
    char passwd[50];    

    //get attributes
    struct termios info;
    ioctl(0,TCGETS, &info); 

    //save a copy of original attributes
    struct termios save = info;

    if (info.c_lflag & ICANON)
        printf("Terminal driver is in canonical mode\n");
    else
        printf("Terminal driver is in non-canonical mode\n");

    printf("Password:");

    //make the echo bit off and set attributes
    info.c_lflag &= ~ECHO;        
    ioctl(0, TCSETS, &info);

    //get password from user
    fgets(passwd, 50, stdin);
    char *q;
    q = strchr(passwd, '\n');
    *q = '\0';

    //now set the attributes back to original
    ioctl(0, TCSETS, &save);

    //compare password and print appropriate message
    int rv = strcmp(passwd, "pucit");
    if (rv == 0)
        printf("\nThe password is correct\n");
    else
        printf("\nThe password is incorrect\n");

    return 0;
}