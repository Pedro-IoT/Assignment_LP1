#Makefile for "Sistema_Bancario" C++ application
#Created by Pedro Maia 16/05/2025
PROG = Sistema_Bancario
CC = g++
CPPFLAGS = -O0 -g -Wall -pedantic
LDFLAGS =

OBJS = main.o ContaBancaria.o

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

main.o: main.cpp sistema.h
	$(CC) $(CPPFLAGS) -c main.cpp

ContaBancaria.o: ContaBancaria.cpp sistema.h
	$(CC) $(CPPFLAGS) -c ContaBancaria.cpp

clean:
	del /Q $(PROG).exe $(OBJS)
