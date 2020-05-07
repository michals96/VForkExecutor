# VForkExecutor  
*Programming in UNIX systems 202*0  
**Michal Stefaniuk**  
## Project target
The goal of the project was to create a program that would execute given compiled another program using vfork() function and compare it to the usual execution in the shell or with the fork. 
## How to run
Program has attachted `Makefile` that is responsible for building the project. Clone the repository to your local device and follow below instructions.

Build the project type

    make
Clean the project

    make clean
   Run the project
   

    make run
   When you run the project a mockup shell will appear
   

    VForkExecutor $:
  Type any program's name to execute it as a child process created by `vfork()`. My proposition for the project is to use bubble-sort algorithm stored in **sort.c**, for example

    VForkExecutor $: ./sort type_of_system_call
  There are three types of system calls for user to choose from.
  * fork
  * vfork
  * vfork_err
 
To exit the program just type

    VForkExecutor $: exit

 


 

## Workflow description  
  Each one of system calls implements different behaviour. Example usage
  

    VFrokExecutor $: ./sort fork
This will run `./sort` in child process created in `./fork`. Then user is asked to input an array. Next task will be bubble sorting given array and regarding type of system call, array will be printed in another process created by **fork()** or **vfork()** 
  


## Performance of system calls
Here show examples of errors and describe differences between system calls

The  `vfork()`  function has the same effect as  `fork()`, except that the behavior is undefined if the process created by  `vfork()`  either modifies any data other than a variable of type  `pid_t`  used to store the return value from  `vfork()`, or returns from the function in which  `vfork()`  was called, or calls any other function before successfully calling  `_exit()`  or one of the  `exec()`  family of functions.

So by calling  `printf()`  in your child code, your code is already undefined. 

> Note that even a call to  `exit()`  could  sometimes lead to undefined behavior

According to **LINUX man**
>`vfork()` differs from `fork(2)` in that the calling thread is suspended until the child terminates (either normally, by calling `_exit(2)`, or abnormally, after delivery of a fatal signal), or it makes a call to `execve(2)`. Until that point, the child shares all memory with its parent, including the stack.

## Implementation
