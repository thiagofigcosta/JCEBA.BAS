FORMAT=.cpp
CC=g++
SRC=$(wildcard *$(FORMAT))
MANUAL=joguinho_de_controle_de_estoque_de_bomba_atomica.BAS$(FORMAT)
OBJ= $(SRC:$(FORMAT)=.o)
EXEC=bin/JCEBA.BAS
CFLAGS=-c -w -Wall
LDFLAGS=-lglut -lGLU -lGL -lm -lSOIL -lalut -lopenal -lGLEW

all: $(SCR) $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(FORMAT).o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXEC)

manualRun:
	$(CC) $(MANUAL) -o $(EXEC) $(LDFLAGS)
	./$(EXEC)

run: all
	./$(EXEC)

rerun: clean all
	rm -rf *.o
	./$(EXEC)

install: all
	@mv $(EXEC) $(bindir)/
	@cp -R JCEBA/ $(bindir)/

rebuild: clean all

crossCWin:
	i686-w64-mingw32-cpp $(MANUAL) -o win32.exe $(LDFLAGS)
