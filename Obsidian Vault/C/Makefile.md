`left: right` is left requires right.

`%.o`, `%.c` for all `.o`, `.c` files. `$<` is automatic variable for `.c` files; `$@` is automatic variable for `.o` or executable.

`SOURCES=$(wildcard $(SRC)/*.c)` selects all `.c` files in `$(SRC)`. `$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))` creates middle (`$(OBJ)/%.o`) for all first (`$(SRC)/%.c`) in last (`$(SOURCES)`).


## Example

#### Init

To build foo.o from foo.c, locally:

```Makefile
foo.o: foo.c
	$(CC) -c $< -o $@
```


To do the same, but with any needed header files in src/:

```Makefile
SRC := src

foo.o: foo.c
    $(CC) -I$(SRC) -c $< -o $@
```


To do the same, but with the source file in src/:

```
SRC := src

foo.o: $(SRC)/foo.c
    $(CC) -I$(SRC) -c $< -o $@
```


To do that, but put the object file in obj/:

```
SRC := src
OBJ := obj

$(OBJ)/foo.o: $(SRC)/foo.c
    $(CC) -I$(SRC) -c $< -o $@
```


A pattern rule that will do that for any such object file (obj/foo.o, obj/bar.o, ...):

```
SRC := src
OBJ := obj

$(OBJ)/%.o: $(SRC)/%.c
    $(CC) -I$(SRC) -c $< -o $@
```


To create the list of desired objects:

```
SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
```


And a rule to cover them all:

```
all: $(OBJECTS)
```


Putting it all together:

```
SRC := src
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

all: $(OBJECTS)
    $(CC) $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c
    $(CC) -I$(SRC) -c $< -o $@
```


Note that this has one big shortcoming: is does not track dependencies on header files. This can be done automatically, but it's a subtle trick; it can wait until you've mastered this much.


#### All

Now

```
all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJS) -o $@
```