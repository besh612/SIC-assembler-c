#include "groupL_LIB.h"

void init_optable()
{
    int hex;
    char opcode[6];
    char code_num[6];
    FILE *file = fopen("input/op_tab.sic", "r");
    while (!feof(file))
    {
        fscanf(file, "%s\t%s", opcode, code_num);
        OPCODETAB *node = (OPCODETAB *)malloc(sizeof(OPCODETAB));
        //atoi: 문자열을 정수로 변환
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