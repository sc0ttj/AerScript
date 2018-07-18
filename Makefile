CFLAGS = -W -Wunused -Wall -I. -g -o -Ofast -DPH7_ENABLE_MATH_FUNC
LDFLAGS = -Wl,--export-dynamic -ldl -lm -rdynamic
CC = gcc
INCLUDES =

ENGINE_OBJS =\
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


all: psharp dummy.lib

clean:
	rm -f psharp $(ENGINE_OBJS) *.lib

style:
	astyle $(ASTYLE_FLAGS) --recursive ./*.c,*.h

psharp: $(ENGINE_OBJS)
	$(CC) -o psharp $(LDFLAGS) $^

%.o: %.c
	$(CC) -c $(INCLUDES) $(CFLAGS) -o $@ -c $<

dummy.lib: ext/dummy/dummy.c
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -fPIC -o dummy.lib ext/dummy/dummy.c
