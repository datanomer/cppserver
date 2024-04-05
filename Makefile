.PHONY: client.cpp main.cpp

compile: client.cpp main.cpp
	g++ client.cpp -o client
	g++ main.cpp -o server

clean:
	rm -rf client server
