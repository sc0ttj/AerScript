CFLAGS = -W -Wunused -Wall -I. -Ofast
LDFLAGS =
CC = gcc
INCLUDES =

OBJ =\
	api.o \
	builtin.o \
	compile.o \
	constant.o \
	hashmap.o \
	interpreter.o \
	lex.o \
	lib.o \
	memobj.o \
	oo.o \
	parse.o \
	vfs.o \
	vm.o


all: main

clean:
	rm -f *.o ph7

main: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o ph7

.c.o:
	$(CC) -c $(INCLUDES) $(CFLAGS) $<
