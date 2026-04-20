CC = g++

.PHONY: run
run: 
	$(CC) -o main main.cpp 

.PHONY: clean
clean: 
	$(CC) rm main
