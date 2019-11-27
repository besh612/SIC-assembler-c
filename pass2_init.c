#include "groupL_LIB.h"

void read_pass1_output()
{ // pass1 결과를 읽음

    FILE *file = fopen("output/output_pass1.txt", "r");
    if (file == NULL)
    {
        printf("file error");
    }

    read_line_pass2(file); // 파일을 라인별로 읽기위한 함수 호출

    fclose(file);
}