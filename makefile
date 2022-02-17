CC = g++

CFLAGS = -Wall -Wextra -std=c++17 

all: dir main.o FindFile.o lib exec

main.o:
	$(CC) $(CFLAGS) -c main.cpp -o bin/main.o

FindFile.o:
	$(CC) $(CFLAGS) -c FindFile.cpp -o bin/FindFile.o

lib:
	ar rcs bin/libFindFile.a bin/FindFile.o

exec:
	$(CC) $(CFLAGS) bin/main.o bin/libFindFile.a -o main
	
dir:
	mkdir bin

clean:
	rm -r bin main.o FindFile.o FindFile.a main


