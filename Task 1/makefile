main: main.o queue.o
	gcc -g main.o queue.o -o main.exe

queue.o: queue.c queue.h
	gcc -g -c queue.c

main.o: main.c
	gcc -g -c main.c

clean:
	rm *.o output