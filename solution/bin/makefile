# Implementação do AUTOCOMPLETE
# Autor: JONAS RAFAEL

PROG = exec
CC = g++
FLAGS = -O3 -g -Wall -pedantic
OBJS = main.o

$(PROG): $(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)

main.o: main.cpp Termo.h Lista.h ListaOrdenada.h FileService.h Autocomplete.h
	$(CC) $(FLAGS) -c main.cpp

clean:
	rm -f $(PROG) $(OBJS)
