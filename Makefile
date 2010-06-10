all: twit

twit: main.o
	g++ main.o -o twit.o
main.o: main.cpp
	g++ main.cpp -lncurses -lcurl -o main.o
clean:
	rm -rf *o twit
