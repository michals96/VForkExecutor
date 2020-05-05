# Makefile for building app
# by Michal Stefaniuk

CC_C = gcc

all:
	$(CC_C) fork.c -o fork
	$(CC_C) main.c -o sort

fork:
	$(CC_C) fork.c -o fork

main:
	$(CC_C) main.c -o sort

clean:
	rm -f fork sort