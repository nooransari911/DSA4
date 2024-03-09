## (Learn Makefiles)[https://makefiletutorial.com/#makefile-cookbook]


## Why do Makefiles exist?

Makefiles are used to help decide which parts of a large program need to be recompiled. In the vast majority of cases, C or C++ files are compiled. Note that Make can also be used beyond compilation too, when you need a series of instructions to run depending on what files have changed. This tutorial will focus on the C/C++ compilation use case.




## Makefile Syntax

A Makefile consists of a set of rules. A rule generally looks like this:

`
targets: prerequisites
	command
	command
	command
	command
`

- The targets are file names, separated by spaces. Typically, there is only one per rule.
- The commands are a series of steps typically to make the target(s) when target(s) does not already exist. These need to start with a tab character, not spaces.
- The prerequisites are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are also called dependencies.




## The essence of Make

Let's start with a hello world example:

`
hello:
	echo "Hello, World"
	echo "This line will print if the file hello does not exist."
`

There's already a lot to take in here. Let's break it down:

- We have one target called hello
- This target has no prerequisites
- This target has two commands

We'll then run make hello. As long as the hello file does not exist, the commands will run. If hello does exist or if prerequisite is *older* than hello, no commands will run.




## Variables

Variables can only be strings. You'll typically want to use :=, but = also works. Value after := is automatically interpreted as string.

Reference variables using either ${} or $().




## Targets
A target can have multiple targets as prerequisites. This will make all those targets.

$@ is an automatic variable that contains the target name.

The first rule listed will run by default if make is called without specifying a target.

When there are multiple targets for a rule, the commands will be run for each target.




## Automatic Variables and Wildcards
### * Wildcard

Both * and % are called wildcards in Make, but they mean entirely different things. * searches your filesystem for matching filenames. I suggest that you always wrap it in the wildcard function, because otherwise you may fall into a common pitfall described below.

// Print out file information about every .c file
`print: $(wildcard *.c)
	ls -la  $?`


* may be used in the target, prerequisites, or in the wildcard function.


Danger: * may not be directly used in a variable definitions; use * in wildcard functions

// the wrong and right way
`thing_wrong := *.o # Don't do this!; '*' will not get expanded
thing_right := $(wildcard *.o)`


Danger: When * matches no files, it is left as it is (unless run in the wildcard function)

// Stays as *.o if there are no files that match this pattern :(
two: *.o 


### % Wildcard

% is really useful, but is somewhat confusing because of the variety of situations it can be used in.

- When used in "matching" mode, it matches one or more characters in a string. This match is called the stem.
- When used in "replacing" mode, it takes the stem that was matched and replaces that in a string.
- % is most often used in rule definitions and in some specific functions.




## Automatic Variables

There are many automatic variables, but often only a few show up commonly:
- `$@`  target; same as name of target
- `#?`  Outputs all prerequisites newer than the target
-	`#^`	Outputs all prerequisites




## Fancy Rules
### Implicit Rules

Make loves c compilation. And every time it expresses its love, things get confusing. Perhaps the most confusing part of Make is the magic/automatic rules that are made. Make calls these "implicit" rules. I don't personally agree with this design decision, and I don't recommend using them, but they're often used and are thus useful to know.


Here's a list of implicit rules:

- Compiling a C program: n.o is made automatically from n.c with a command of the form $(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@
- Compiling a C++ program: n.o is made automatically from n.cc or n.cpp with a command of the form $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
- Linking a single object file: n is made automatically from n.o by running the command $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@


The important variables used by implicit rules are:

- `CC`: Program for compiling C programs; default cc
- `CXX`: Program for compiling C++ programs; default g++
- `CFLAGS`: Extra flags to give to the C compiler
- `CXXFLAGS`: Extra flags to give to the C++ compiler
- `CPPFLAGS`: Extra flags to give to the C preprocessor
- `LDFLAGS`: Extra flags to give to compilers when they are supposed to invoke the linker


Let's see how we can now build a C program without ever explicitly telling Make how to do the compililation:
```
CC = gcc // Flag for implicit rules
CFLAGS = -g // Flag for implicit rules. Turn on debug info

// Implicit rule 1: blah is built via the C linker implicit rule
// Implicit rule 2: blah.o is built via the C compilation implicit rule, because blah.c exists


blah: blah.o

blah.c:
	echo "int main() { return 0; }" > blah.c

clean:
	rm -f blah*
```




### Static Pattern Rules

Static pattern rules are another way to write less in a Makefile, but I'd say are more useful and a bit less "magic". Here's their syntax:
```
targets...: target-pattern: prereq-patterns ...
   commands
```

The essence is that the given target is matched by the target-pattern (via a % wildcard). Whatever was matched is called the stem. The stem is then substituted into the prereq-pattern, to generate the target's prereqs.


A typical use case is to compile .c files into .o files. Here's the manual way:

```
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
foo.o: foo.c
bar.o: bar.c
all.o: all.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
```


Here's the more efficient way, using a static pattern rule:

```
objects = foo.o bar.o all.o
all: $(objects)

# These files compile via implicit rules
# Syntax - targets ...: target-pattern: prereq-patterns ...
# In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to be "foo".
# It then replaces the '%' in prereq-patterns with that stem
$(objects): %.o: %.c

all.c:
	echo "int main() { return 0; }" > all.c

%.c:
	touch $@

clean:
	rm -f *.c *.o all
```




Static Pattern Rules and Filter

While I introduce functions later on, I'll foreshadow what you can do with them. The filter function can be used in Static pattern rules to match the correct files. In this example, I made up the .raw and .result extensions.

```
obj_files = foo.result bar.o lose.o
src_files = foo.raw bar.c lose.c

all: $(obj_files)
# Note: PHONY is important here. Without it, implicit rules will try to build the executable "all", since the prereqs are ".o" files.
.PHONY: all 

# Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
$(filter %.o, $(obj_files)): %.o: %.c
	echo "target: $@ prereq: $<"

# Ex 2: .result files depend on .raw files. Though we don't actually make the .result file.
$(filter %.result, $(obj_files)): %.result: %.raw
	echo "target: $@ prereq: $<" 

%.c %.raw:
	touch $@

clean:
	rm -f $(src_files)
```




Pattern Rules

Pattern rules are often used but quite confusing. You can look at them as two ways:

- A way to define your own implicit rules
- A simpler form of static pattern rules


Let's start with an example first:

# Define a pattern rule that compiles every .c file into a .o file

```
%.o : %.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
```

Pattern rules contain a '%' in the target. This '%' matches any nonempty string, and the other characters match themselves. ‘%’ in a prerequisite of a pattern rule stands for the same stem that was matched by the ‘%’ in the target.
