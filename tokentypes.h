

#ifndef TOKENTYPES_H
#define TOKENTYPES_H

/* 
 *
 */


#include <stdlib.h>

#include <string.h>

enum type_enum_t {
    type_enum_int,
    type_enum_string
};


struct id_token_t
{
    char* lexeme;
};

struct type_token_t
{
    enum type_enum_t type;
};


struct create_table_token_t
{
    char* lexeme;
};

struct drop_table_token_t
{
    char* lexeme;
};


/* Ctors */
struct id_token_t* make_idtoken (const char* lexeme);
struct type_token_t* make_typetoken (const char* lexeme);
struct create_table_token_t* make_createtabletoken (const char* lexeme);
struct drop_table_token_t* make_droptabletoken (const char* lexeme);


#endif // TOKENTYPES_H



