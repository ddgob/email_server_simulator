CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/ArquivoDeComandos.o $(OBJ)/Email.o $(OBJ)/Entrada.o $(OBJ)/CaixaDeEntrada.o $(OBJ)/ContaDeUsuario.o $(OBJ)/ServidorDeEmails.o
HDRS = $(INC)/ArquivoDeComandos.hpp $(INC)/Email.hpp $(INC)/Entrada.hpp $(INC)/CaixaDeEntrada.hpp $(INC)/ContaDeUsuario.hpp $(INC)/ServidorDeEmails.hpp
CFLAGS = -Wall -c -g -I$(INC)  -std=c++17

EXE = $(BIN)/programa.exe

all: clean compile

compile: $(EXE)

run: 
	./$(EXE)

$(BIN)/programa.exe: $(OBJS)
	$(CC) $(OBJS) -o $(BIN)/programa.exe $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/ArquivoDeComandos.o: $(HDRS) $(SRC)/ArquivoDeComandos.cpp
	$(CC) $(CFLAGS) $(SRC)/ArquivoDeComandos.cpp -o $(OBJ)/ArquivoDeComandos.o

$(OBJ)/Email.o: $(HDRS) $(SRC)/Email.cpp
	$(CC) $(CFLAGS) $(SRC)/Email.cpp -o $(OBJ)/Email.o

$(OBJ)/Entrada.o: $(HDRS) $(SRC)/Entrada.cpp
	$(CC) $(CFLAGS) $(SRC)/Entrada.cpp -o $(OBJ)/Entrada.o

$(OBJ)/CaixaDeEntrada.o: $(HDRS) $(SRC)/CaixaDeEntrada.cpp
	$(CC) $(CFLAGS) $(SRC)/CaixaDeEntrada.cpp -o $(OBJ)/CaixaDeEntrada.o

$(OBJ)/ContaDeUsuario.o: $(HDRS) $(SRC)/ContaDeUsuario.cpp
	$(CC) $(CFLAGS) $(SRC)/ContaDeUsuario.cpp -o $(OBJ)/ContaDeUsuario.o

$(OBJ)/ServidorDeEmails.o: $(HDRS) $(SRC)/ServidorDeEmails.cpp
	$(CC) $(CFLAGS) $(SRC)/ServidorDeEmails.cpp -o $(OBJ)/ServidorDeEmails.o

clean: 
	rm -f obj/*.o bin/*.exe