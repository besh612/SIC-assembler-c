#include "groupL_LIB.h"

int sym_tab_check()
{
    SYMTAB *data = SYMLIST;
    while (data != NULL)
    {
        if (strcmp(LABEL, data->LABEL) == 0)
        {
            return 1;
        }
        data = data->link;
    }
    return 0;
}
