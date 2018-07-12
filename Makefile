ph7: api.c builtin.c compile.c constant.c hashmap.c lex.c lib.c memobj.c oo.c parse.c vfs.c vm.c interpreter.c
	cc -o ph7 api.c builtin.c compile.c constant.c hashmap.c lex.c lib.c memobj.c oo.c parse.c vfs.c vm.c interpreter.c -W -Wunused -Wall -I. -Ofast

clean:
	rm -rf *.o
	rm -rf ph7
