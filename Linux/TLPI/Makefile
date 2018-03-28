CC = gcc
CFLAGS = -g -Wall -std=c99
VPATH = FileIO

dir = ./build
bin = $(dir)/Copy $(dir)/Read $(dir)/Lseek

all : $(bin)

$(bin) : $(objs)
	$(CC) $(CFLAGS) $< -o $@

base = ErrorFunctions.o GetNum.o
$(base) : TlpiHead.h

clean:
	rm -f *.o 
