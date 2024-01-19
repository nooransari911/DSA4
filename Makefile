CC=gcc
OPT=O0
CFLAGS=-g -march=native -I src
INC=-I /home/ansarimn/Downloads/testing/


# Directories for src, obj, bins
SRC=src
OBJ=obj
SRCtest=testing
OBJtest=testing/obj

BIN0=bin/main0
BIN1=bin/main1
BINtest=bin/test


# wildcard, patsubst for all *.o, *.c files
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
SRCStest=$(wildcard $(SRCtest)/*.c)
OBJStest=$(patsubst $(SRCtest)/%.c, $(OBJtest)/%.o, $(SRCStest))
BUILD0=$(SRC)/main/main0.c
BUILD1=$(SRC)/main/main1.c




# init for all, test targets
init: $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -O2 -c $< -o $@


init0: $(OBJ)/main0.o

$(OBJ)/main0.o: $(SRC)/main/main0.c
	$(CC) $(CFLAGS) -O2 -c $< -o $@


init1: $(OBJ)/main1.o

$(OBJ)/main1.o: $(SRC)/main/main1.c
	$(CC) $(CFLAGS) -O2 -c $< -o $@


init_test: $(OBJStest)

$(OBJtest)/%.o: $(SRCtest)/%.c
	$(CC) $(CFLAGS) -O2 -c $< -o $@




# Main targets;
# all: for DSA2;
# test: for testing purposes;
all0: $(BIN0)

$(BIN0): $(OBJ) $(OBJ)/main0.o
	$(CC) $(CFLAGS) $(OBJS) $(OBJ)/main0.o -o $@



all1: $(BIN1)

$(BIN1): $(OBJ) $(OBJ)/main1.o
	$(CC) $(CFLAGS) $(OBJS) $(OBJ)/main1.o -o $@


test: $(BINtest)

$(BINtest): $(OBJtest)
	$(CC) $(CFLAGS) $(OBJStest) -o $@

run: hello
hello:
	$(BIN1)










# -O1, -O2 main targets;
L1: bin/L1

bin/L1: $(OBJ)
	$(CC) $(CFLAGS) -O1 $(OBJS) -o $@



L2: bin/L2

bin/L2: $(OBJ)
	$(CC) $(CFLAGS) -O2 $(OBJS) -o $@





# clean everything in obj, bin, /testing/obj;
clean:
	$(RM) -rf bin/* $(OBJ)/* $(OBJtest)/*
