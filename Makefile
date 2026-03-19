all: guia-basica-c guia-avanzada-c

guia-basica-c: guia-basica-c.o
	gcc -Wall -Wextra -pedantic guia-basica-c.o -o guia-basica-c

guia-basica-c.o: guia-basica-c.c
	gcc -Wall -Wextra -pedantic -c guia-basica-c.c -o guia-basica-c.o

guia-avanzada-c: guia-avanzada-c.o
	gcc -Wall -Wextra -pedantic guia-avanzada-c.o -o guia-avanzada-c

guia-avanzada-c.o: guia-avanzada-c.c
	gcc -Wall -Wextra -pedantic -c guia-avanzada-c.c -o guia-avanzada-c.o

clean:
	rm -f *.o guia-basica-c guia-avanzada-c

.PHONY: all clean