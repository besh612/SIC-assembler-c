#include "groupL_LIB.h"

void found_op_value()
{ //opcode_pass2 값을 찾는다

    FILE *file = fopen("input/op_tab.sic", "r");
    if (file == NULL)
    {
        printf("file error");
    }

    char str[SIZE];
    char *token;

    while (fgets(str, SIZE, file) != NULL)
    { //opcode_pass2 값을 각각 다 불러와서 저장한다.

        char opcode_pass2[10] = {"null"}, op_value[10] = {"null"};
        int j = 0;

        token = strtok(str, "\t\n");
        while (token != NULL)
        {

            if (j == 0)
                strcpy(opcode_pass2, token);
            if (j == 1)
                strcpy(op_value, token);
            j++;
            token = strtok(NULL, "\t\n");
        }

        strcpy(opcode_table[pass2_k].opcode_pass2, opcode_pass2);
        strcpy(opcode_table[pass2_k].op_value, op_value);

        pass2_k++;
    }

    for (int m = 0; m < pass2_i; m++)
    { //pass1에 있는 opcode에 해당하는 값들을 다 찾아서 저장한다.
        strcmp(state[m].op_value, "null");
        for (int n = 0; n < pass2_k; n++)
        {
            if (strcmp(state[m].opcode_pass2, opcode_table[n].opcode_pass2) == 0)
            {
                strcpy(state[m].op_value, opcode_table[n].op_value);
            }
        }
    }

    fclose(file);
}