# Implementação do AUTOCOMPLETE
# Autor: JONAS RAFAEL

PROG = exec
CC = g++
FLAGS = -O3 -g -Wall -pedantic
OBJS = Main.o

$(PROG): $(OBJS)
	$(CC) $(FLAGS) -o $(PROG) $(OBJS)

main.o: Main.cpp Termo.h Lista.h ListaOrdenada.h FileService.h Autocomplete.h
	$(CC) $(FLAGS) -c Main.cpp

clean:
	rm -f $(PROG) $(OBJS)

