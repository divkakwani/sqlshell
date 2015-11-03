

all: a.out post-build 

a.out: parser.tab.o lex.yy.o
	@echo compiling...
	gcc -lfl utils/list.c tokentypes.c lex.yy.c parser.tab.c -o a.out

parser.tab.o:
	@echo generating parser.tab.c
	bison -d parser.y -o parser.tab.c

lex.yy.o:
	@echo generating lex.yy.c
	flex -o lex.yy.c lexer.l 

post-build: 
	@echo running a.out
	./a.out

clean:
	rm -r build/*

