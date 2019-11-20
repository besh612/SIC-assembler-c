#include "myLib.h";

int main()
{
    int value;
    int flag;
    int size = 1;
    int LOCCTR = 0;

    FILE *open_sic_codes = fopen("files/input.sic", "r");
    FILE *save_after_pass1 = fopen("output_pass1.txt", "w");

    while (1)
    {
        read_line(open_sic_codes, NULL);
        if (!strcmp(LABEL, "."))
        {
            continue;
        }
        else
        {
            if (!strcmp(OPCODE, "START") || flag == 1)
            {
                char *END;
                START_LOC = (int)strtol(OPERAND, &END, 16);
                LOCCTR = (int)strtol(OPERAND, &END, 16);
                flag = 0;
            }
            else if (LABEL[0] != '\0')
            {
                value = sym_tab_check();
                if (value == 0)
                {
                    add_sym_tab();
                }
                else
                {
                    printf("ERROR - 1");
                    exit(1);
                }
            }
            else
            {
                printf("ERROR - 2");
                exit(1);
            }
        }

        if (strcmp(OPCODE, "END") == 0)
        {
            LENGTH = LOCCTR - START_LOC;
            fprintf(save_after_pass1, "\t%s\t%s\t%s\n", LABEL, OPCODE, OPERAND);
            break;
        }
        fprintf(save_after_pass1, "%d\t%s\t%s\t%s\n", LOCCTR, LABEL, OPCODE, OPERAND);

        if (feof(open_sic_codes))
        {
            printf("END");
            exit(1);
        }

        if (!strcmp(OPCODE, "BYTE"))
        {
            if (!atoi(OPERAND))
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
                LOCCTR = LOCCTR + atoi(OPERAND) * 3;
            else if (!strcmp(OPCODE, "RESB"))
            {
                size = atoi(OPERAND);
                LOCCTR = LOCCTR + size;
            }
            else if (!strcmp(OPCODE, "END"))
                printf("PASS1 종료\n");
            else
            {
                printf("ERROR - 3");
                exit(1);
            }
        }
    }
    fclose(open_sic_codes);
    fclose(save_after_pass1);
}