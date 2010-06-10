all: twit

twit:
	g++ main.cpp -lncurses -lcurl -o twit
clean:
	rm twit 
