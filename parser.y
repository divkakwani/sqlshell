
%{

#include <stdio.h>
#include <stdlib.h>

#include "utils/list.h"

#include "tokentypes.h"
#include "astnodetypes.h"
#include "executenode.h"

#define YYSTYPE void*

/* extern declarations */
extern int yylex ();


/* Forward declarations */
int yyerror (const char *s);

struct stmt_t* statement;

%}

%token ID CREATETABLE TYPE DROPTABLE

%%

/* A minimal SQL grammar. Allows following instruction types:
 * 1. CREATE TABLE
 * 2. DELETE
 * 3. DROP TABLE
 * 4. INSERT
 * 5. SELECT
 * 6. UPDATE
*/
// create-table-statement : CREATE TABLE base-table-name (column-id data-type)


stmt:               create-table-stmt
                    {
                        statement = malloc (sizeof (struct stmt_t));
                        statement->kind = cts_kind;
                        statement->u.ct_stmt = $1;
                    }
                |
                    drop-table-stmt
                    {
                        statement = malloc (sizeof (struct stmt_t));
                        statement->kind = dts_kind;
                        statement->u.dts_stmt = $1;
                    };



create-table-stmt:  CREATETABLE base-table-name fields 
                    {
                        struct createtable_stmt_t* s = make_createtable_stmt (((struct id_token_t*)$2)->lexeme, (struct list*)$3);
                        $$ = s;
                    };

base-table-name:    ID 
                    {
                        $$ = $1;
                    }

fields:             field fields
                    {
                        list_push_back ((struct list*)$2, &((struct field_t*)$1)->elem);
                        $$ = $2;
                    }
                |   
                    {
                        struct list* fields = malloc (sizeof (struct list));
                        list_init (fields);
                        $$ = fields;
                    }
                    ;

field:              field-name field-type
                    {
                        $$ = make_field (((struct id_token_t*)$1)->lexeme, ((struct type_token_t*)$2)->type);
                    };

field-name:         ID   { $$ = $1; };
field-type:         TYPE { $$ = $1; };



drop-table-stmt:    DROPTABLE base-table-name
                    {
                        struct droptable_stmt_t* dts = make_droptable_stmt (((struct id_token_t*)$2)->lexeme);
                        $$ = dts;
                    }




%%


int
main (void)
{
    yyparse ();
    execute_stmt (statement);
    return 0;
}


int
yyerror (const char *err_mesg) 
{
    fprintf (stderr, "Error encountered: %s\n", err_mesg);  
}






