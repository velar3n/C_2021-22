CC = gcc
CFLAGS = -Wall -ansi

all : project.o functions.o
	$(CC) $(CFLAGS) -o game project.o functions.o

*.o : *.c
	$(CC) $(FLAGS) -c *.c
