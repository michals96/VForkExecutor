# Makefile for building app
# by Michal Stefaniuk

CC_C = gcc

all:
	$(CC_C) fork.c -o fork
	$(CC_C) sort.c -o sort

fork:
	$(CC_C) fork.c -o fork

sort:
	$(CC_C) sort.c -o sort

clean:
	rm -f fork sort