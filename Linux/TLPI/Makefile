.PHONY: clean
CC = gcc
CFLAGS = -g -Wall -std=c99

BUILD_DIR = ./build
all: $(BUILD_DIR)/Copy $(BUILD_DIR)/Read $(BUILD_DIR)/Lseek

$(BUILD_DIR)/Copy:
	$(CC) $(CFLAGS) ./FileIO/Copy.c GetNum.c ErrorFunctions.c -o $(BUILD_DIR)/Copy

$(BUILD_DIR)/Read:
	$(CC) $(CFLAGS) ./FileIO/Read.c GetNum.c ErrorFunctions.c -o $(BUILD_DIR)/Read

$(BUILD_DIR)/Lseek:
	$(CC) $(CFLAGS) ./FileIO/Lseek.c GetNum.c ErrorFunctions.c -o $(BUILD_DIR)/Lseek

clean:
	rm -f *.o $(BUILD_DIR)/Read $(BUILD_DIR)/Copy $(BUILD_DIR)/Lseek
