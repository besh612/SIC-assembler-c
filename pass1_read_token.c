#include "groupL_LIB.h"

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