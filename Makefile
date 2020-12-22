all: client.c processor.c
	gcc -o processor processor.c
	gcc -o client client.c
