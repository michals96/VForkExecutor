#ifndef BENCHMARK_H
#define BENCHMARK_H

/**
    Bubble-sorts given array of n-size.

    @param array Array that will be sorted
    @param n     Size of array
    @return      Type void
*/
void sort(int array[], int n);

/**
    Prints given array of n-size.

    @param array Array that will be printed
    @param n     Size of array
    @return      Type void
*/
void printarr(int array[], int n);

/**
    Initialize given array of n-size with random ints <0,50>.

    @param array Array that will be initialized
    @param n     Size of array
    @return      Type void
*/
void initializeArray( int array[], int n);

#endif