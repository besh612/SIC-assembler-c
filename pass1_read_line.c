#include "groupL_LIB.h"

void read_line_pass1(FILE *file)
{
    char temp[SIZE];
    char l_char;

    l_char = read_token(file, LABEL);

    if (LABEL[0] == '.')
    {
        if (l_char == '\t')
        {
            char is_enter;
            while (is_enter != '\n')
            {
                is_enter = getc(file);
            }
        }
        OPCODE[0] = OPERANDS[0] = '\0';
    }
    else
    {
        l_char = read_token(file, OPCODE);
        if (l_char == '\n')
        {
            OPERANDS[0] = '\0';
            return;
        }
        read_token(file, OPERANDS);
    }
}