#include "groupL_LIB.h"

void change_six_bit(char *result)
{ //6bit 공간에 값을 담고 나머지 값들은 0으로 초기화
    char temp[7] = "000000";
    int s = 5;
    for (int j = strlen(result) - 1; j >= 0; j--)
    {
        temp[s] = result[j];
        s--;
    }
    strcpy(result, temp);
}