all: control.c
	gcc -o control control.c

run: control
	./control
