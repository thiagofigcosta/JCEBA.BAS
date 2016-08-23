CC=g++
SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)
EXEC=JCEBA.BAS
CFLAGS=-c -Wsign-compare -Wwrite-strings -Wall
LDFLAGS=-lglut -lGLU -lGL -lm -lSOIL

all: $(SCR) $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXEC)

run: all
	./$(EXEC)

install: all
	@mv $(EXEC) $(bindir)/

rebuild: clean all
