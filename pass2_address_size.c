#include "groupL_LIB.h"

char *address_size() //전체 주소의 크기
{
    int size;
    int start_address = atoi(state[0].address);
    int last_address = atoi(state[pass2_i - 1].address);

    char str[7];
    char str2[7];
    char str3[7];

    size = last_address - start_address;
    int reminder;
    int j = 0;

    while (size != 0)
    {
        reminder = size % 10;
        size = size / 10;

        switch (reminder)
        {

        case 0:
            str[j++] = '0';
            break;
        case 1:
            str[j++] = '1';
            break;
        case 2:
            str[j++] = '2';
            break;
        case 3:
            str[j++] = '3';
            break;
        case 4:
            str[j++] = '4';
            break;
        case 5:
            str[j++] = '5';
            break;
        case 6:
            str[j++] = '6';
            break;
        case 7:
            str[j++] = '7';
            break;
        case 8:
            str[j++] = '8';
            break;
        case 9:
            str[j++] = '9';
            break;
        }
    }

    int l = j;
    int m = 0;

    for (m = 0; m < l; m++)
    {
        str2[m] = str[--j];
    }
    str2[m] = '\0';

    strcpy(str3, change_Hexa(str2));
    change_six_bit(str3);
    return str3;
}