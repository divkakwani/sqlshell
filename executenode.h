

#ifndef _EXECUTE_NODE_H
#define _EXECUTE_NODE_H


#include "astnodetypes.h"

void execute_stmt (struct stmt_t* statement);
void execute_createtable_stmt (struct createtable_stmt_t* cts);

#endif 
