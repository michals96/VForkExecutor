# VForkExecutor  
*Programming in UNIX systems 202*0  
**Michal Stefaniuk**  
  
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
  
  Each one of them implements different behaviour which will be described thoroughly in next section. Example usage
  

    VFrokExecutor $: ./sort fork
This will run `./sort` in child process created in `./fork`. Then user is asked to input an array. Next task will be bubble sorting given array and regarding type of system call, array will be printed in another process created by **fork()** or **vfork()** 

 

## Project target & Workflow description  
  
The goal of the project was to create a program that would execute given compiled another program using vfork() function and compare it to the usual execution in the shell or with the fork.  

## Performance & Implementation
