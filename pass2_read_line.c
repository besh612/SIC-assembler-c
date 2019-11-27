#include "groupL_LIB.h"

void read_line_pass2(FILE *file)
{
    char str[SIZE];
    char *token;

    while (fgets(str, SIZE, file) != NULL)
    {

        int j = 0;
        char address[10] = "null", label[10] = "null", opcode_pass2[10] = "null", operand[10] = "null";

        token = strtok(str, "\t\n");

        while (token != NULL)
        {
            if (j == 0)
            {
                strcpy(address, token);
            }
            if (j == 1)
                strcpy(label, token);
            if (j == 2)
                strcpy(opcode_pass2, token);
            if (j == 3)
                strcpy(operand, token);
            j++;
            token = strtok(NULL, "\t\n");
        }

        if (strcmp(operand, "null") == 0)
        {
            strcpy(operand, opcode_pass2);
            strcpy(opcode_pass2, label);
            strcpy(label, "null");
        }

        strcpy(state[pass2_i].address, address);
        strcpy(state[pass2_i].label, label);
        strcpy(state[pass2_i].opcode_pass2, opcode_pass2);
        strcpy(state[pass2_i].operand, operand);

        pass2_i++;
    }
}