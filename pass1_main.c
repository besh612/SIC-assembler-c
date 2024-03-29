#include "groupL_LIB.h"

int pass1_main(char *file)
{
    int LOCCTR = 0;
    int flag = 1;
    int found = 2;

    FILE *open_sic_codes = fopen(file, "r");
    FILE *save_after_pass1 = fopen("output/output_pass1.txt", "w");

    while (1)
    {
        int size = 1;
        read_line_pass1(open_sic_codes);

        // . 라인 무시
        if (strcmp(LABEL, ".") == 0)
            continue;
        else
        {
            //if this is not a comment line (LABEL 존재 파악)
            if (LABEL[0] != '\0')
            {
                found = sym_tab_check();
                if (found == 0)
                {
                    add_sym_tab();
                }
                else
                {
                    printf("ERROR - 1 duplicate symbol\n");
                    exit(1);
                }
            }
        }
        //if OPCODE = 'START'
        if (strcmp(OPCODE, "START") == 0)
        {
            START_LOC = (int)strtol(OPERANDS, NULL, 16);
            LOCCTR = (int)strtol(OPERANDS, NULL, 16);
            flag = 0;
            printf("%d\t%s\t%s\t%s\n", LOCCTR, LABEL, OPCODE, OPERANDS);
            fprintf(save_after_pass1, "%d\t%s\t%s\t%s\n", LOCCTR, LABEL, OPCODE, OPERANDS);
            continue;
        }

        printf("%d\t%s\t%s\t%s\n", LOCCTR, LABEL, OPCODE, OPERANDS);
        fprintf(save_after_pass1, "%d\t%s\t%s\t%s\n", LOCCTR, LABEL, OPCODE, OPERANDS);
        if (search_opcode_tab())
        {
            LOCCTR = LOCCTR + 3;
        }

        else if (strcmp(OPCODE, "BYTE") == 0)
        {
            if (atoi(OPERANDS) == 0)
            {
                int i;
                for (i = 0; i < SIZE; i++)
                {
                    if (OPERANDS[i] == '\0')
                        break;
                }
                //check index addr mode
                if (OPERANDS[0] == 'X')
                    size = 1;
                else
                    size = i - 3;
            }
            LOCCTR = LOCCTR + size;
        }
        else if (strcmp(OPCODE, "WORD") == 0)
            LOCCTR = LOCCTR + 3;
        else if (strcmp(OPCODE, "RESW") == 0)
        {
            size = atoi(OPERANDS) * 3;
            LOCCTR = LOCCTR + size;
        }
        else if (strcmp(OPCODE, "RESB") == 0)
        {
            size = atoi(OPERANDS);
            LOCCTR = LOCCTR + size;
        }
        else if (strcmp(OPCODE, "END") == 0)
        {
            LENGTH = LOCCTR - START_LOC;
            printf("PASS1 END (LENGTH[%d])\n", LENGTH);
            break;
        }
        else
        {
            printf("ERROR - 2 invalid operation code\n");
            exit(1);
        }
    }

    fclose(open_sic_codes);
    fclose(save_after_pass1);

    return 0;
}