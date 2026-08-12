CC = g++

.PHONY: run
run: 
	$(CC) -o main main.cpp 

.PHONY: clean
clean: 
	rm main

.PHONY: sfml
sfml: 
	$(CC) main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system 
