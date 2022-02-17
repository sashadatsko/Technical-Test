CC = g++

CFLAGS = -Wall -Wextra -std=c++17 

all: main.o FindFile.o lib exec

main.o:
	$(CC) $(CFLAGS) -c main.cpp -o bin/main.o

FindFile.o:
	$(CC) $(CFLAGS) -c FindFile.cpp -o bin/FindFile.o

lib:
	ar rcs bin/libFindFile.a bin/FindFile.o

exec:
	$(CC) $(CFLAGS) bin/main.o bin/libFindFile.a -o main

clean:
	rm -r bin/* main


