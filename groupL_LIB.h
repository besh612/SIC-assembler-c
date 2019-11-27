#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50

int START_LOC;
int LENGTH;
int LOCCTR;
int HEXNUM;
int OPERAND;
int pass2_i;
int pass2_k;
char result[7];
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

typedef struct STATE
{
    char address[SIZE];
    char label[SIZE];
    char opcode_pass2[SIZE];
    char operand[SIZE];
    char op_value[SIZE];
    char t_address[SIZE];
} STATE;

typedef struct OPCODE_PASS2
{

    char opcode_pass2[SIZE];
    char op_value[SIZE];

} OPCODE_PASS2;

OPCODE_PASS2 opcode_table[SIZE];
OPCODETAB *OPCODELIST;
struct STATE state[SIZE];
SYMTAB *SYMLIST;

int sym_tab_check();
int search_opcode_tab();
int pass1_main();
int pass2_main();

char read_token(FILE *file, char *TOKEN);
char *address_size();
char *change_Hexa(char *num);
char *pass2_operand_change_hex(int number);

void add_sym_tab();
void init_optable();
void output_pass2();
void found_op_value();
void read_pass1_output();
void read_pass1_output();
void found_target_address();
void read_line_pass1(FILE *file);
void read_line_pass2(FILE *file);
void make_object_code(char *temp);
void change_six_bit(char *result);