DIR_LIB = ./Lib
DIR_BIN = ./build
DIR_OBJ = ./obj

DIR_FILE = ./FileIO
DIR_PROC = ./Process

CC = gcc
CFLAGS = -g -Wall -I$(DIR_LIB) -std=c99

BIN = Copy Read Lseek Tee Fcntl
TARGET = $(foreach v, $(BIN), $(DIR_BIN)/$(v))

LIB = $(wildcard $(DIR_LIB)/*.c)
LIB_OBJ = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir $(LIB)))

all : $(LIB_OBJ)

$(DIR_OBJ)/%.o : $(DIR_LIB)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(TARGET)

define GEN_TARGET
$$(DIR_BIN)/$(1) : $$(DIR_FILE)/$(1).c
	$$(CC) $$(CFLAGS) $$(LIB_OBJ) $$< -o $$@
endef

$(foreach v, $(BIN), $(eval $(call GEN_TARGET,$(v))))

BIN = ModifyEnv Jmp
TARGET = $(foreach v, $(BIN), $(DIR_BIN)/$(v))
all : $(TARGET)

define GEN_TARGET2
$$(DIR_BIN)/$(1) : $$(DIR_PROC)/$(1).c
	$$(CC) $$(CFLAGS) $$(LIB_OBJ) $$< -o $$@
endef

$(foreach v, $(BIN), $(eval $(call GEN_TARGET2,$(v))))

.PHONY : clean
clean :
	rm -f $(DIR_BIN)/* $(DIR_OBJ)/*.o
