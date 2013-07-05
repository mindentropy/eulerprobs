CC=gcc

CFLAGS= -g 
INCLUDE = -I./include
LDFLAGS = -lm
BIN_DIR=bin
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj


SRC_FILES := $(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.c))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
BIN_FILES := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SRC_FILES))

vpath %.h $(INCLUDE_DIR)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)

all: euler_probs

euler_probs: $(BIN_FILES)
	
$(BIN_DIR)/%: %.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -rfv $(OBJ_DIR)/*.o $(BIN_DIR)/* 
