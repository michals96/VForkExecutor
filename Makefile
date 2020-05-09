# Makefile for building app
# @author Michal Stefaniuk

CC_C = gcc

all:
	$(CC_C) fork.c -o fork
	$(CC_C) sort.c -o sort
	$(CC_C) benchmark.c -o benchmark

benchmark:
	$(CC_C) benchmark.c benchmark.h -o benchmark

fork:
	$(CC_C) fork.c fork.h -o fork

sort:
	$(CC_C) sort.c sort.h -o sort

run:
	./fork
clean:
	rm -f fork sort benchmark