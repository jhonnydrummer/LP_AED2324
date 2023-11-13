//
// Created by Pedro Marques on 04/10/2023.
//

#ifndef PROJETOLPAED1_PROJETO_H
#define PROJETOLPAED1_PROJETO_H
#define MAXCOLUMNS 10

/**possivel estrutura**/
typedef struct {
    char **data;
    int rows;
    int cols;
} DynamicMatrix;


int main_projeto(int argc, const char * argv[]);

char * content_to_binary(char * string);

void add_to_matrix(char ** matrix, int row, int collum, int numRow, int numCollum, char * value);

void remove_from_matrix(DynamicMatrix *matrix, int row, int col);

void check_segment(char segment);

void seach_string(const char *sequence, const char *words[], int numWords);

void sort_crescent();

void sort_decrescent();

char * create_matrix(int numRows, int numCollums, char ** matrix);

void print_matrix(char ** matrix);

#endif //PROJETOLPAED1_PROJETO_H
