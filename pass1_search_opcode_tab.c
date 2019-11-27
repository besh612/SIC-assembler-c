#include "groupL_LIB.h"

int search_opcode_tab()
{
    OPCODETAB *temp = OPCODELIST;
    while (temp != NULL)
    {
        if (strcmp(temp->NAME, OPCODE) == 0)
        {
            HEXNUM = temp->HEXNUM;
            return 1;
        }
        else
            temp = temp->link;
    }
    return 0;
}