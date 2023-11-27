//
// Created by Pedro Marques on 04/10/2023.
//

#ifndef PROJETOLPAED1_PROJETO_H
#define PROJETOLPAED1_PROJETO_H
#define MAXCOLUMNS 10

/***********************************************************************************************************************
****************************************** SECÇÃO DAS STRUCTURES*******************************************************
***********************************************************************************************************************/

typedef struct DynamicMatrix{
    char **data;
    int rows;
    int cols;
} DYNAMICMATRIX;

typedef struct Words_Holder{
    DYNAMICMATRIX DynamicMatrixC1;
    DYNAMICMATRIX DynamicMatrixC2;
    DYNAMICMATRIX Matrix1;
    DYNAMICMATRIX Matrix2;
}WORDS_HOLDER;

typedef struct Val_Ad_Words_Holder{
    DYNAMICMATRIX DM1;
    int date;
    char code;
}VAL_AD_WORDS_HOLDER;

typedef struct Node_Ll_Words_Holder{
    WORDS_HOLDER WH1;
    int date;
    char * pToNext;
    char * pToPrevious;
}NODE_LL_WORDS_HOLDER;
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

int main_projeto(int argc, const char * argv[]);

char * AD_WORDS_HOLDER(int size, int N, char * pfirst); //Header da função para o Array Dinamico

char * content_to_binary(char * string);

//void add_to_matrix(char ** matrix, int row, int collum, int numRow, int numCollum, char * value, const char *palavra);

void add_to_matrix(char **matrix, int row, int collum, int numRow, int numCollum, const char *palavra);

char gerarPalavraAleatoria(char *palavra, int tamanho);

void remove_from_matrix(DYNAMICMATRIX *matrix, int row, int col);

void check_segment(char **matrix,char **matrix2);

void seach_string(const char *sequence, const char *words[], int numWords);

void sort_crescent(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);
void sort_decrescent(int arr[], int left, int right);

char * create_matrix(int numRows, int numCollums, char ** matrix);

void string_to_binary(char **matriz,int numpalavras);

void decimal_to_binary(int value, char **matriz, int line, int column);

void print_matrix(char ** matrix);



#endif //PROJETOLPAED1_PROJETO_H
