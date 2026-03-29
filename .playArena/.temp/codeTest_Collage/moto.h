#ifndef STARTUP_BANNER_H
#define STARTUP_BANNER_H

#include <stdio.h>

/* ANSI color codes */
#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

static inline void lunixHeadingStartup(void) {
    printf(GREEN "student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ gcc mohit_singh.c\n");
    printf("student@administrator-HP-Compaq-4000-Pro-SFF-PC:~$ ./a.out\n" RESET);
    printf("\n");
}

void printLn(){
    printf("\n");
}

#endif
