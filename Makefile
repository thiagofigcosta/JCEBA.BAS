CC=g++
SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)
EXEC=bin/JCEBA.BAS
CFLAGS=-c -w -Wall
LDFLAGS=-lglut -lGLU -lGL -lm -lSOIL -lalut -lopenal

all: $(SCR) $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXEC)

run: all
	./$(EXEC)

rerun: clean all
	./$(EXEC)
	rm -rf *.o

install: all
	@mv $(EXEC) $(bindir)/

rebuild: clean all
