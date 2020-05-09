/**
    benchmark.c

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
#include <stdbool.h> 
#include <sys/time.h>
#include <time.h>
#include "benchmark.h"

int main(int argc, char** argv)
{
    int n = 5;
    int array[n];  

    initializeArray(array, n);

    struct timeval  tv1, tv2;

    gettimeofday(&tv1, NULL);

    sort(array, n);

    int status;
    pid_t pid;

    bool isFork = false;
    bool isVfork = false;

    if(strcmp(argv[1], "vfork") == 0)
    {
        isVfork = true;
        pid = vfork();
    }
    else if(strcmp(argv[1], "fork") == 0)
    {
        isFork = true;
        pid = fork();
    }
    else
    {
        pid = fork();
    }


    if ( pid < 0 )
    {
        printf("*** ERROR: forking child process failed\n");
        exit(1);
    }
    else if( pid == 0 )
    {
        gettimeofday(&tv2, NULL);

        printf ("Time = %f seconds\n",
            (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
            (double) (tv2.tv_sec - tv1.tv_sec));

        if(isVfork && strcmp(argv[1], "vfork") == 0)
            exit(0); 
    }
    else 
    {              
        if(isFork)
            while (wait(&status) != pid); 
    }

  return 0;
}

void sort(int array[], int n)
{
    int c, d, swap = 0;
    for (c = 0 ; c < n - 1; c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (array[d] > array[d+1]) /* For decreasing order use < */
                {
                    swap       = array[d];
                    array[d]   = array[d+1];
                    array[d+1] = swap;
                }
        }
    }
}

void initializeArray( int array[], int n)
{
    int i;

    srand(time(NULL));

    for( i=0; i<n; ++i)
    {
        array[i]=(rand()%51);
    }
}

void printarr(int array[], int n)
{
    int i;
    printf("Sorted list in ascending order: ");

    for ( i= 0; i < n; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n"); 
}