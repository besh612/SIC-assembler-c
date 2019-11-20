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

SYMTAB *SYMLIST;
OPCODES *OPLIST;
OPCODETAB *OPCODELIST;

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

int sym_tab_check();
int search_opcode_tab();
char read_token(FILE *file, char *TOKEN);
void read_line(FILE *file, int state);
void make_object_code(char *temp);