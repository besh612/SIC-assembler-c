#include "myLib.h"

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

int pass1_main()
{
    int LOCCTR = 0;
    int flag = 1;
    int size = 1;
    int value = 3;

    FILE *open_sic_codes = fopen("input/input.sic", "r");
    FILE *save_after_pass1 = fopen("output/output_pass1.txt", "w");

    while (1)
    {
        read_line(open_sic_codes, 1);
        if (!strcmp(LABEL, "."))
        {
            continue;
        }
        else
        {
            if (!strcmp(OPCODE, "START"))
            {
                if (flag == 1)
                {
                    char *END;
                    START_LOC = (int)strtol(OPERANDS, &END, 16);
                    LOCCTR = (int)strtol(OPERANDS, &END, 16);
                    flag = 0;
                }
                else if (flag == 0)
                {
                    printf("ERROR - 1\n");
                    exit(1);
                }
            }

            if (LABEL[0] != '\0')
            {
                value = sym_tab_check();
                if (value == 0)
                {
                    printf("value is 0\n");
                    add_sym_tab();
                }
                else
                {
                    printf("ERROR - 2\n");
                    exit(1);
                }
            }
        }

        if (strcmp(OPCODE, "END") == 0)
        {
            LENGTH = LOCCTR - START_LOC;
            fprintf(save_after_pass1, "\t%s\t%s\t%s\n", LABEL, OPCODE, OPERANDS);
            break;
        }
        fprintf(save_after_pass1, "%d\t%s\t%s\t%s\n", LOCCTR, LABEL, OPCODE, OPERANDS);

        if (feof(open_sic_codes))
        {
            printf("END\n");
            exit(1);
        }

        if (!strcmp(OPCODE, "BYTE"))
        {
            if (!atoi(OPERANDS))
            {
                int res;
                int i;
                for (i = 0; i < SIZE; i++)
                {
                    if (OPERANDS[i] == '\0')
                        break;
                }
                if (OPERANDS[0] == 'X')
                    res = 1;
                else
                    res = i - 3;
                size = res;
                LOCCTR = LOCCTR + size;
            }
            else if (!strcmp(OPCODE, "WORD") || search_opcode_tab())
                LOCCTR = LOCCTR + 3;
            else if (!strcmp(OPCODE, "RESW"))
                LOCCTR = LOCCTR + atoi(OPERANDS) * 3;
            else if (!strcmp(OPCODE, "RESB"))
            {
                size = atoi(OPERANDS);
                LOCCTR = LOCCTR + size;
            }
            else if (!strcmp(OPCODE, "END"))
                printf("PASS1 종료\n");
            else
            {
                printf("ERROR - 3\n");
                exit(1);
            }
        }
    }
    fclose(open_sic_codes);
    fclose(save_after_pass1);
    return 0;
}