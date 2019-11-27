#include "groupL_LIB.h"

char *pass2_operand_change_hex(int number)
{
    char temp[10];
    char result[7];

    int remainder;
    int j = 0;
    int m = 0;

    if (number == 0)
    {
        result[0] = '0';
        result[1] = '0';
        result[2] = '\0';
        return result;
    }
    else
    {
        while (number != 0)
        {
            remainder = number % 16;
            number = number / 16;
            switch (remainder)
            {
            case 0:
                temp[j++] = '0';
                break;
            case 1:
                temp[j++] = '1';
                break;
            case 2:
                temp[j++] = '2';
                break;
            case 3:
                temp[j++] = '3';
                break;
            case 4:
                temp[j++] = '4';
                break;
            case 5:
                temp[j++] = '5';
                break;
            case 6:
                temp[j++] = '6';
                break;
            case 7:
                temp[j++] = '7';
                break;
            case 8:
                temp[j++] = '8';
                break;
            case 9:
                temp[j++] = '9';
                break;
            case 10:
                temp[j++] = 'A';
                break;
            case 11:
                temp[j++] = 'B';
                break;
            case 12:
                temp[j++] = 'C';
                break;
            case 13:
                temp[j++] = 'D';
                break;
            case 14:
                temp[j++] = 'E';
                break;
            case 15:
                temp[j++] = 'F';
                break;
            }
        }

        int l = j;
        for (m = 0; m < l; m++)
        {
            result[m] = temp[--j];
        }
        result[m] = '\0';

        return result;
    }
}
