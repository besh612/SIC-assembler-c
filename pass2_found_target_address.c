#include "groupL_LIB.h"

void found_target_address()
{ // 해당하는 target_address 주소를 찾는다.

    for (int j = 0; j < pass2_i; j++)
    {
        strcpy(state[j].t_address, "null");
        for (int m = 0; m < pass2_i; m++)
        {
            if (strcmp(state[j].operand, state[m].label) == 0)
                strcpy(state[j].t_address, state[m].address);
        }
    }
}