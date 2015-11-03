

#include <stdlib.h>

#include "tokentypes.h"


struct id_token_t*
make_idtoken (const char* lexeme)
{
    struct id_token_t* p = malloc (sizeof (struct id_token_t));
    p->lexeme = strdup (lexeme);
    return p;
}


struct type_token_t*
make_typetoken (const char* lexeme)
{
    struct type_token_t* p = malloc (sizeof (struct type_token_t));

    if (strcmp (lexeme, "int") == 0)
        p->type = type_enum_int;
    else
        if (strcmp (lexeme, "string") == 0)
            p->type = type_enum_string;

    return p;
}

struct create_table_token_t* 
make_createtabletoken (const char* lexeme)
{
    struct create_table_token_t* p = malloc (sizeof (struct create_table_token_t));
    p->lexeme = strdup (lexeme);
    return p;
}

