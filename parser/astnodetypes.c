


#include <stdlib.h>
#include <string.h>

#include "astnodetypes.h"


struct createtable_stmt_t*
make_createtable_stmt (const char* table_name, struct list* fields)
{
    struct createtable_stmt_t* p = malloc (sizeof (struct createtable_stmt_t));
    strcpy (p->table_name, table_name);
    p->fields = fields;
    return p;
}

struct droptable_stmt_t*
make_droptable_stmt (const char* table_name) 
{
    struct droptable_stmt_t* p = malloc (sizeof (struct droptable_stmt_t));
    strcpy (p->table_name, table_name);
    return p;
}

struct field_t*
make_field (const char* name, enum type_enum_t type)
{
    struct field_t* p = malloc (sizeof (struct field_t));
    strcpy(p->name, name);
    p->type = type;
    return p;
}
