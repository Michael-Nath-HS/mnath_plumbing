all: client.c processor.c
	gcc -o processor.out processor.c
	gcc -o client.out client.c
run: 
	./processor.out & ./client.out
clean:
	rm *.out