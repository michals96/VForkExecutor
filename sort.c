/**
    sort.c

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
#include "sort.h"

int main(int argc, char** argv)
{
  int array[100], n, c;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  sort(array, n);

  int status;
  pid_t pid;

  bool isFork = false;
  bool isVfork = false;

  if(strcmp(argv[1], "vfork") == 0 || strcmp(argv[1], "vfork_err") == 0)
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
    printf("Child: ");
    printarr(array, n);
    printf("\n"); 
    
    if(isVfork && strcmp(argv[1], "vfork") == 0)
      exit(0); 
    // This line will 
    // Cause child process to end which will prevent seg fault
  }
  else 
  { 
    printf("Parent: ");
    printarr(array, n);                
    printf("\n"); 

    if(isFork)
      while (wait(&status) != pid); 
    // Make sure that parent process finishes when using fork
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

void printarr(int array[], int n)
{
  int i;
  printf("Sorted list in ascending order:\n");

  for ( i= 0; i < n; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n"); 
}