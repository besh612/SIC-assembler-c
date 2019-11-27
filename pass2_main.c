#include "groupL_LIB.h"

int pass2_main()
{
    read_pass1_output();
    found_op_value();
    found_target_address();

    char temp[10];
    char bit_address[7];
    char add_size[7];
    strcpy(add_size, address_size());

    char object_code[7];
    char bit_op_value[7];
    char bit_t_address[7];
    char word_value[7];
    char byte_value[7];

    int j = 0;

    FILE *save_after_pass2 = fopen("output/output_pass2.txt", "w");

    for (int j = 0; j < pass2_i; j++)
    {
        if (strcmp(state[j].opcode_pass2, "END") == 0)
        {
            strcpy(bit_address, change_Hexa(state[0].address));
            change_six_bit(bit_address);
            printf("E%s\n", bit_address);
            fprintf(save_after_pass2, "E%s\n", bit_address);
            break;
        }

        if (strcmp(state[j].label, "FIRST") == 0)
        {
            strcpy(bit_address, change_Hexa(state[0].address));

            change_six_bit(bit_address);
            printf("H%s  00%s%s\n", state[0].label, bit_address, add_size);
            fprintf(save_after_pass2, "H%s  00%s%s\n", state[0].label, bit_address, add_size);
        }

        if ((strcmp(state[j].opcode_pass2, "START") == 0))
        {
            continue;
        }

        else if (strcmp(state[j].opcode_pass2, "WORD") == 0)
        {
            strcpy(bit_address, change_Hexa(state[j].address));
            change_six_bit(bit_address);

            strcpy(word_value, change_Hexa(state[j].operand));
            change_six_bit(word_value);

            printf("T%s03%s\n", bit_address, word_value);
            fprintf(save_after_pass2, "T%s03%s\n", bit_address, word_value);
        }

        else if (strcmp(state[j].opcode_pass2, "BYTE") == 0)
        {
            char token1[10];
            char token2[10];

            strcpy(token1, strtok(state[j].operand, "'"));
            strcpy(token2, strtok(NULL, "'"));

            strcpy(bit_address, change_Hexa(state[j].address));
            change_six_bit(bit_address);

            if (strcmp(token1, "C") == 1)
            {
                char length[7] = {
                    0,
                };
                for (int l = 0; pass2_operand_change_hex(strlen(token2) / 2)[l] != '\0'; ++l)
                {
                    length[l] = pass2_operand_change_hex(strlen(token2) / 2)[l];
                }
                change_six_bit(length);

                printf("T%s03%s\n", bit_address, length);
                fprintf(save_after_pass2, "T%s03%s\n", bit_address, length);
            }
            else
            {
                char length[7] = {
                    0,
                };
                for (int l = 0; pass2_operand_change_hex(strlen(token2))[l] != '\0'; ++l)
                {
                    length[l] = pass2_operand_change_hex(strlen(token2))[l];
                }
                change_six_bit(length);
                printf("T%s03%s\n", bit_address, length);
                fprintf(save_after_pass2, "T%s03%s\n", bit_address, length);
            }
        }

        else if (strcmp(state[j].opcode_pass2, "RESW") == 0)
        {
            continue;
        }

        else if (strcmp(state[j].opcode_pass2, "RESB") == 0)
        {
            continue;
        }

        else
        {
            strcpy(bit_address, change_Hexa(state[j].address));
            change_six_bit(bit_address);

            strcpy(bit_op_value, change_Hexa(state[j].op_value));
            strcpy(object_code, bit_op_value);
            strcpy(bit_t_address, change_Hexa(state[j].t_address));

            if (strlen(object_code) < 2)
            {
                if (strcmp(object_code, "00") != 0)
                {
                    object_code[1] = object_code[0];
                    object_code[0] = '0';
                    object_code[2] = '\0';
                }
            }
            strcat(object_code, bit_t_address);
            printf("T%s03%s \n", bit_address, object_code);
            fprintf(save_after_pass2, "T%s03%s \n", bit_address, object_code);
        }
    }
    return 0;
}
