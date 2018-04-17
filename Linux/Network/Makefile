CC = gcc
CFLAGS = -g -Wall

DIR_BIN = ./build

BIN = HelloServer HelloClient
OBJS = $(BIN:=.o)
.SUFFIXES: .c .o
$(OBJS) : Util.h
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(DIR_BIN)/$@

all : $(BIN)

HelloServer.o: HelloServer.c
HelloClient.o: HelloClient.c

.PHONY : clean
clean :
	rm -rf $(DIR_BIN)/* *.o

