CC = g++

all:
	$(CC) -std=c++11 -o a.exe Bellman.cpp

clean:
	rm -f a.exe

