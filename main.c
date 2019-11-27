#include "groupL_LIB.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        fputs("error: no input file found\n", stderr);
        exit(1);
    }
    init_optable();
    pass1_main(argv[1]);
    pass2_main();
}