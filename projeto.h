//
// Created by Pedro Marques on 04/10/2023.
//

#ifndef PROJETOLPAED1_PROJETO_H
#define PROJETOLPAED1_PROJETO_H
#define MAXCOLUMNS 10

/**exemplo de uma estrutura**/
typedef struct ex{
    int ex1;
    int ex2;
    char ex3 [1][1];
}EX;


int main_projeto(int argc, const char * argv[]);

int decimal_to_binary(int value);

int string_to_binary(char * string);

void add_to_matrix(char matrix[][MAXCOLUMNS], int rows, int cols);

void remove_from_matrix(char ** c1, int row, int collum, int numRow, int numCollum);

void check_segment(char segment);

void seach_string(const char *sequence, const char *words[], int numWords);

void sort_crescent();

void sort_decrescent();

char * create_matrix(int numRows, int numCollums, char ** matrix);

void print_matrix(char ** matrix);

#endif //PROJETOLPAED1_PROJETO_H
