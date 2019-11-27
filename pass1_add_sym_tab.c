#include "groupL_LIB.h"

void add_sym_tab()
{
    SYMTAB *node = (SYMTAB *)malloc(sizeof(SYMTAB));
    strcpy(node->LABEL, LABEL);
    node->ADDR = LOCCTR;
    node->link = NULL;

    if (SYMLIST == NULL)
        SYMLIST = node;
    else
    {
        node->link = SYMLIST;
        SYMLIST = node;
    }
}
