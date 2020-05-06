#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

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

int main(int argc, char** argv)
{
  int array[100], n, c;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  int   status;
  int no = 10;
  pid_t pid = vfork();
  

  if ( pid < 0 )
  {
      printf("*** ERROR: forking child process failed\n");
      exit(1);
  }
  else if(pid ==0)
  {
      sort(array, n);
      printf("1: %d\n", no);

      printf("Sorted list in ascending order:\n");
      for (c = 0; c < n; c++)
        printf("%d\t", array[c]);
      printf("\n");

      // exit(0); This line will cause child process to end
      // which will prevent seg fault
  }
  else 
  {            
      sort(array, n);    
      printf("2: %d\n", no); 

      printf("Sorted list in ascending order:\n");
      for (c = 0; c < n; c++)
        printf("%d\t", array[c]);
      printf("\n");        

      // while (wait(&status) != pid); necessary line to make 
      // sure that parent process finishes when using fork
  }
  
  //printf("\n%s \n", argv[3]);
  return 0;
}