/**
    fork.c

    Purpose: Runs as a child process created in fork.c
    Processes passed array and prints it in nested vfork()

    @author Michal Stefaniuk
    @version 1.0
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "fork.h"


void  main(void)
{
    char  line[1024];             
    char  *argv[64];              

    while (1) 
    {                  
        printf("Shell -> ");     
        gets(line);            
        printf("\n");
        parse(line, argv);      
        if (strcmp(argv[0], "exit") == 0)  
            exit(0);            
        execute(argv);           
    }
}

void parse(char *line, char **argv)
{
    while (*line != '\0') {       
        while (*line == ' ' || *line == '\t' || *line == '\n')
            *line++ = '\0';     
        *argv++ = line;          
        while (*line != '\0' && *line != ' ' && 
                *line != '\t' && *line != '\n') 
            line++;             
    }
    *argv = '\0';                 
}

     
void execute(char **argv)
{
    pid_t  pid;
    int    status;
    
    if ((pid = fork()) < 0) {     
        printf("*** ERROR: forking child process failed\n");
        exit(1);
    }
    else if (pid == 0) {          
        if (execvp(argv[0], argv) < 0) {     
            printf("*** ERROR: exec failed\n");
            exit(1);
        }
        exit(0);
    }
    else {                                 
        while (wait(&status) != pid);
    }
}

                