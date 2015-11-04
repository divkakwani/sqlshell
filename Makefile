

all: sqlshell post-build 

sqlshell: parser.tab.o lex.yy.o
	@echo compiling...
	gcc -lfl utils/list.c lexer/tokentypes.c parser/astnodetypes.c executor/executenode.c \
		     lexer/lex.yy.c parser/parser.tab.c main.c -o sqlshell

parser.tab.o:
	@echo generating parser.tab.c
	bison -d parser/parser.y -o parser/parser.tab.c

lex.yy.o:
	@echo generating lex.yy.c
	flex -o lexer/lex.yy.c lexer/lexer.l 

post-build: 
	@echo Build successful. Run sqlshell to get started.

install:

clean:
	rm parser/parser.tab.c parser/parser.tab.h lexer/lex.yy.c sqlshell

