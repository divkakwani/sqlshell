

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "utils/list.h"
#include "astnodetypes.h"
#include "executenode.h"

void
execute_stmt (struct stmt_t* statement) 
{
    if (statement->kind == cts_kind)
    {
        execute_createtable_stmt (statement->u.ct_stmt);
    }
    else
        if (statement->kind == dts_kind)
        {
            execute_droptable_stmt (statement->u.dts_stmt);
        }
}

void
execute_createtable_stmt (struct createtable_stmt_t* cts)
{
    /* To execute a create table statement, we have to write
     * its schema on to the hard disk. As per our convention, 
     * the schema will be written to the file db_files/db_name/schema.
     */
    char pathname[100] = "db_files/";
    strcat (pathname, cts->table_name);

    mkdir (pathname, 0755);

    strcat (pathname, "/schema");
    FILE* file = fopen (pathname, "w");

    /* Write schema - by successively writing down each field
     * TODO: Separate this part out */
    struct list_elem* e;
    for (e = list_begin (cts->fields); e != list_end (cts->fields); e = list_next (e))
    {
        struct field_t* field = list_entry (e, struct field_t, elem);
        fprintf (file, "%s    %d\n", field->name, field->type);
    }
}


void
execute_droptable_stmt (struct droptable_stmt_t* dts)
{
    /* Delete the dir db_files/db_name */
    char command[200] = "rm -r db_files/";
    strcat (command, dts->table_name);
    system (command);
}




