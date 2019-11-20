#include "myLib.h";

void init_optable()
{
    char opcode[6];
    char code_num[6];
    int hex;
    FILE *file = fopen("files/op_tab.sic", "r");
    while (!feof(file))
    {
        fscanf(file, "$s\t$s", opcode, code_num);
        OPCODETAB *node = (OPCODETAB *)malloc(sizeof(OPCODETAB));
        hex = atoi(code_num);
        strcpy(node->NAME, opcode);
        node->HEXNUM = hex;
        node->link = NULL;
        if (OPCODELIST == NULL)
        {
            OPCODELIST = node;
        }
        else
        {
            node->link = OPCODELIST;
            OPCODELIST = node;
        }
    }
    fclose(file);
}