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
	lexer.o \
	lib.o \
	memobj.o \
	oop.o \
	parser.o \
	vfs.o \
	vm.o

ASTYLE_FLAGS =\
	--style=java \
	--indent=force-tab \
	--attach-closing-while \
	--attach-inlines \
	--attach-classes \
	--indent-classes \
	--indent-modifiers \
	--indent-switches \
	--indent-cases \
	--indent-preproc-block \
	--indent-preproc-define \
	--indent-col1-comments \
	--pad-oper \
	--pad-comma \
	--unpad-paren \
	--delete-empty-lines \
	--align-pointer=name \
	--align-reference=name \
	--break-one-line-headers \
	--add-braces \
	--verbose \
	--formatted \
	--lineend=linux


all: main

clean:
	rm -f *.o ph7

style:
	astyle $(ASTYLE_FLAGS) --recursive ./*.c,*.h

main: $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o ph7

.c.o:
	$(CC) -c $(INCLUDES) $(CFLAGS) $<
