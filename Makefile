all: guia-basica-c guia-avanzada-c ej-debug-c ej-anexo-integrador-c ej-lista-enlazada

guia-basica-c: guia-basica-c.o
	gcc -Wall -Wextra -pedantic guia-basica-c.o -o guia-basica-c

guia-basica-c.o: guia-basica-c.c
	gcc -Wall -Wextra -pedantic -c guia-basica-c.c -o guia-basica-c.o

guia-avanzada-c: guia-avanzada-c.o
	gcc -Wall -Wextra -pedantic guia-avanzada-c.o -o guia-avanzada-c

guia-avanzada-c.o: guia-avanzada-c.c
	gcc -Wall -Wextra -pedantic -c guia-avanzada-c.c -o guia-avanzada-c.o

ej-debug-c: ej-debug-c.o
	gcc -Wall -Wextra -pedantic ej-debug-c.o -o ej-debug-c

ej-debug-c.o: ej-debug-c.c
	gcc -Wall -Wextra -pedantic -c ej-debug-c.c -o ej-debug-c.o

ej-anexo-integrador-c: ej-anexo-integrador-c.o
	gcc -Wall -Wextra -pedantic ej-anexo-integrador-c.o -o ej-anexo-integrador-c

ej-anexo-integrador-c.o: ej-anexo-integrador-c.c
	gcc -Wall -Wextra -pedantic -c ej-anexo-integrador-c.c -o ej-anexo-integrador-c.o

ej-lista-enlazada: ej-lista-enlazada.o
	gcc -Wall -Wextra -pedantic ej-lista-enlazada.o -o ej-lista-enlazada

ej-lista-enlazada.o: ej-lista-enlazada.c
	gcc -Wall -Wextra -pedantic -c ej-lista-enlazada.c -o ej-lista-enlazada.o

clean:
	rm -f *.o guia-basica-c guia-avanzada-c ej-debug-c ej-anexo-integrador-c ej-lista-enlazada

.PHONY: all clean