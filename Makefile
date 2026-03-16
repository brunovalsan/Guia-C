all: guia-basica-c

guia-basica-c: guia-basica-c.o
	gcc -Wall -Wextra -pedantic guia-basica-c.o -o guia-basica-c

guia-basica-c.o: guia-basica-c.c
	gcc -Wall -Wextra -pedantic -c guia-basica-c.c -o guia-basica-c.o

clean:
	rm *.o guia-basica-c

.PHONY: all clean