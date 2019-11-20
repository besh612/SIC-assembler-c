#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50

int START_LOC;
int LENGTH;
int LOCCTR;
int HEXNUM;
int OPERAND;
char LABEL[SIZE];
char OPCODE[SIZE];
char OPERANDS[SIZE];

typedef struct SYMTAB
{
    char LABEL[SIZE];
    int ADDR;
    struct SYMTAB *link;
} SYMTAB;

typedef struct OPCODETAB
{
    char NAME[SIZE];
    int HEXNUM;
    struct OPCODETAB *link;
} OPCODETAB;

typedef struct OPCODES
{
    int HEX;
    int OPERAND;
    char *OBJECTCODE;
    int LOC;
    struct OPCODES *link;
} OPCODES;

SYMTAB *SYMLIST;
OPCODES *OPLIST;
OPCODETAB *OPCODELIST;

int sym_tab_check();
int search_opcode_tab();
int pass1_main();

char read_token(FILE *file, char *TOKEN);

void init_optable();
void change_uppercase(char *data);
void read_line(FILE *file, int state);
void make_object_code(char *temp);