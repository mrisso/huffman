### Makefile ###

#Compilador
CC = gcc

#Opções
CFLAGS = -Wall -g

#Fontes
FONTES = $(wildcard *.c)

#Objetos
OBJ = $(FONTES:.c=.o)

#Executáveis
COMPACT = Compacta
DESCOMPACT = Descompacta

all: $(COMPACT) $(DESCOMPACT)

$(COMPACT): $(OBJ)
	$(CC) -o $@ $^

$(DESCOMPACT): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o 

clear:
	rm -rf *.o $(COMPACT) $(DESCOMPACT)
