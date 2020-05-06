#ifndef FORK_H
#define FORK_H

/**
    Takes an input line and returns a zero-terminated array of char pointers.

    Example:
        input: "this    is in  put"
        output: char *argv[4] = {"this", "is", "in", "put"}

    @param line  Input line
    @param argv  Array used in the main program
    @return      Type void
*/
void parse(char *line, char **argv);

/**
    Forks a child process and executes the indicated program in that child process.

    @param argv  Array used in the main program
    @return      Type void
*/
void execute(char **argv);

#endif