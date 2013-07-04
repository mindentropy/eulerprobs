CC=gcc

CFLAGS= -g -Wall 
INCLUDE = -I./include

BIN_DIR=bin
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj


SRC_FILES := $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

vpath %.h $(INCLUDE_DIR)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)

all: 


$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

cscope_clean:
	rm -rfv *.out

clean:
	rm -rfv $(OBJ_DIR)/*.o $(BIN_DIR)/* *.map
