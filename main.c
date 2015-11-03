
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void runsqlcmd (char *cmd);
inline void printprompt (void);

int
main (void)
{

    char *cmdstr;
    size_t cmdlen;

    while (true) 
    {
        printprompt (); 
        
        if (getline (&cmdstr, &cmdlen, stdin) == -1)
            break;

        runsqlcmd (cmdstr);
    }

    printf ("exiting...\n");
    
}

void
printprompt (void)
{
    char *ps = getenv ("SQLSHELL_PS");
    if (!ps)
        ps = "sqlsh> ";

    printf ("%s", ps);
}

void
runsqlcmd (char *cmd)
{
    system (cmd);
}
