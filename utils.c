#include "myLib.h"

char read_token(FILE *file, char *TOKEN)
{
    char temp;
    for (int i = 0; i < SIZE; i++)
    {
        TOKEN[i] = getc(file);
        if (TOKEN[i] == '\0' || TOKEN[i] == '\t' || TOKEN[i] == '\n')
        {
            temp = TOKEN[i];
            TOKEN[i] = '\0';
            return temp;
        }
    }
    return 1;
}

void change_uppercase(char *data)
{
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] >= 65 && data[i] >= 90)
            data[i] -= 32;
    }
}

void read_line(FILE *file, int state)
{
    char temp[SIZE];
    char l_char;

    if (state != 1)
    {
        read_token(file, temp);
        LOCCTR = atoi(temp);
    }

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

int sym_tab_check()
{
    SYMTAB *data = SYMLIST;
    while (data != NULL)
    {
        if (!strcmp(LABEL, data->LABEL))
        {
            return 1;
        }
        data = data->link;
    }
    return 0;
}

void make_object_code(char *temp)
{
    char code[7];
    int len = strlen(temp);

    for (int i = 5; i >= 0; i--)
        if (len - 1 - (5 - i) > -1)
            code[i] = temp[len - 1 - (5 - i)];
    for (int i = 0; i < 6 - len; i++)
        code[i] = '0';
    code[6] = '\0';
    change_uppercase(code);
    strcpy(temp, code);
}

int search_opcode_tab()
{
    OPCODETAB *temp = OPCODELIST;
    while (temp != NULL)
    {
        if (!strcmp(temp->NAME, OPCODE))
        {
            HEXNUM = temp->HEXNUM;
            return 1;
        }
        else
            temp = temp->link;
    }
    return 0;
}