CC	= gcc

#Diretórios
OBJ = ./obj
SRC = ./src
BIN = ./bin/app

#Arquivo
EXECUTAVEL = $(BIN)/programa

all:
#Cria os objetos
	$(CC) -c $(SRC)/main.c -o $(OBJ)/main.o
	$(CC) -c $(SRC)/menus.c -o $(OBJ)/menus.o
	$(CC) -c $(SRC)/cadastrar.c -o $(OBJ)/cadastrar.o
	$(CC) -c $(SRC)/mostrar.c -o $(OBJ)/mostrar.o
	$(CC) -c $(SRC)/buscar_titulo.c -o $(OBJ)/buscar_titulo.o

#Cria executavel
	$(CC) $(OBJ)/*.o -o $(EXECUTAVEL)

run:
	$(EXECUTAVEL)

clean:
	rm -f $(OBJ)/*.o $(EXECUTAVEL)