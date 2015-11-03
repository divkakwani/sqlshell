
// --- License ---

#ifndef ASTNODETYPES_H
#define ASTNODETYPES_H

#include <stdio.h>

#include "tokentypes.h"
#include "utils/list.h"


/* Node types */

struct stmt_t 
{
    enum { cts_kind, ins_kind, dts_kind} kind;
    union
    {
        struct createtable_stmt_t* ct_stmt;
        struct insert_stmt_t*   ins_stmt;
        struct droptable_stmt_t* dts_stmt;
    } u;
    
};


struct createtable_stmt_t 
{
    char table_name[32];
    struct list* fields;
};

struct droptable_stmt_t
{
    char table_name[32];
};

struct field_t
{
    char name[32];
    enum type_enum_t type;
    struct list_elem elem;
};


struct createtable_stmt_t* make_createtable_stmt (const char* table_name,
                                                  struct list* fields);
struct droptable_stmt_t* make_droptable_stmt (const char* table_name);
struct field_t* make_field (const char* name, enum type_enum_t type);

#endif // ASTNODETYPES_H


