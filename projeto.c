/**
    * ==================================================================================================================
    * PROJETO REALIZADO POR:                                                                                           *
    * - PEDRO MARQUES - 38688                                                                                          *
    * - PEDRO MONTEIRO  -                                                                                              *
    * - DIONE ARANTES -                                                                                                *
    * ==================================================================================================================
    * @todo
    * 2
    * funcao que converte decimal para binario
    * funcao que converte string ou char para binario
    *
    * 3
    * funcao de inserir e remover para uma matriz, e o respestivo binario
    *
    * 4
    * correr ambos as matrizes e verificar combinacoes iguais
    *
    * 5
    * passar como argumento a string de pesquisa, corres as matrizes e ves
    * onde se enquadra o segmento em cada parcela da matriz
    * dar print dessa palavra e posicao e versao binaria
    * (passar por argumento para a que converte para binario)
    *
    * 6
    * Ordenar por ordem crescente ou decrescente
    * crescente encontrar o minimo e passar esse para a ultima posicao
    * descrescente encontrar o maximo e passar esse para a primeira posicao
    *
    * 7
    * criar uma struct que deia para passar ambas as matrizes
    *
    **/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "projeto.h"
#include "ctype.h"
#include <time.h>

#define NULL0 -1;
#define NUMROWS 10
#define NUMCOLS 7

DynamicMatrix dynamicMatrix;

char * UFP6[] = { //UFP6 CORRIGIDO
        // 0          1           2         3         4           5          6           7          8           9           a              b           c            d            e            f            g            h              i            j              k             l             m            n             o             p             q              r            s             t             u             v              w             x                y             z              A             B              C               D             E               F             G               H              I              J             K               L              M            N               O                P              Q              R             S               T               U               V              W            X               Y             Z
        "0",  "1",  "10", "11",  "100", "101", "110", "111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111", "100000", "100001", "100010", "100011", "100100", "100101", "100110", "100111", "101000", "101001", "101010", "101011", "101100", "101101", "101110", "101111", "110000", "110001", "110010", "110011", "110100", "110101", "110110", "110111", "111000", "111001", "111010", "111011", "111100", "111101",
};


char** create_Dynamic_Matrix(int lines, int cols) {
    char** matrix = (char**)malloc(lines * sizeof(char*));
    for (int i = 0; i < lines; i++) {
        *(matrix+i) = (char*)malloc(cols * sizeof(char));
    }
    return matrix;
}


void free_Dynamic_Matrix(char** matrix, int lines) {
    for (int i = 0; i < lines; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_Matrix(char** matrix, int lines, int cols, char dados[10][10]) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix+i)+j) = *(*(dados+i)+j);
        }
    }
}

void print_Matrix(char** matrix, int lines, int cols) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", *(*(matrix+i)+j));
        }
        printf("\n");
    }
}


/**requisito 2
 *
 * a codificação tem que ser feito perante  UFP6
 * temos que criar uma funcao para criar a matriz vazia
 * funcao para adicionar os valores na matriz
 * a codificacao tem que ser feita pertante ufp6, em vez de usar acii temos que passar por UFP6[]
 * passar como argumento o array UFP6 para depois comparar o valor que temos com esse
 *
 *
 * **/

/** req 2 **/
int decimal_to_binary(int value){
    //  printf("TESTE-> valor em decimal fica %d\n", value);
    //array com os valores de binario
    // counter for binary array
    printf("The string in binary is ");
    int i = 0;
    int binaryNum[8];
    while (value > 0) {
        // storing remainder in binary array
        binaryNum[i] = value % 2;
        value = value / 2;
        i++;
    }
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    // matriz[][]=binaryNum[j]

    return 0;//return pointer para matriz

}

/** req 2 **/
int string_to_binary(char * string){

    /** a idea é pegar na string original
     * tirar o size
     * correr em loop e separar a string em diferentes char
     * enviar esse char para a funçao decimal_to_binary
     */

    size_t size = strlen(string);
    int value;

    for (int i = 0; i < size; i++) {
        value=string[i]-'0';
        if(isupper(string[i])){
            value=value+19;
            decimal_to_binary(value);
        } else if(value<=9){
            decimal_to_binary(value);
        }else {
            value = value - 39;
            decimal_to_binary(value);
        }
    }
    printf("\n");

    return 0;
}

/** req 3
 * aqui podemos definir onde colocamos os determinados valores dentro das matrizes
 * para teste primeiro damos print a matriz inicial e depois print com a insercao
 *
 * **/

void add_to_matrix(char ** matrix, int row, int collum, int numRow, int numCollum, char * value){
   if(row >=0 && row < numRow && collum >=0 && collum < numCollum){
       *(*(matrix+row)+collum) = *value;
       string_to_binary(value);
   }
   else{
       printf("invalid insert\n");
   }
}

/*
void add_to_matrix(DynamicMatrix *matrix, int row, int col, char value) {
    if (matrix != NULL && row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {
        *(*(matrix->data + row) + col) = value;
    } else {
        printf("Posição inválida na matriz.\n");
    }
}*/

/** req 3 **/
void remove_from_matrix(DynamicMatrix *matrix, int row, int col) {
    if (matrix != NULL && row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {
        // Deslocar os elementos da matriz para cobrir a posição removida
        for (int i = row; i < matrix->rows - 1; i++) {
            for (int j = col; j < matrix->cols - 1; j++) {
                *(*(matrix->data + i) + j) = *(*(matrix->data + i + 1) + j + 1);
            }
        }

        // Reduzir o número de linhas e colunas na matriz
        matrix->rows--;
        matrix->cols--;

        // Realocar memória para a matriz com o novo tamanho
        matrix->data = (char **)realloc(matrix->data, matrix->rows * sizeof(char *));
        for (int i = 0; i < matrix->rows; i++) {
            matrix->data[i] = (char *)realloc(matrix->data[i], matrix->cols * sizeof(char));
        }
    } else {
        printf("Posição inválida na matriz.\n");
    }
}

/** req 4 **/
void check_segment(char segment){

}

/** req 5 **/
void seach_string(const char *sequencia, const char *palavra[], int numPalavras){

    for (int i = 0; i < numPalavras; i++) {
        //Verifica se a sequência de pesquisa ocorre na palavra
        if (strstr(palavra[i], sequencia) != NULL) {
            printf("%s\n", palavra[i]);
        }
    }
}

/** req 6 **/
void sort_crescent(){
    /**
     *  implementação do merge sort (sugestão Prof. Torres)
     */

}

/** req 6 **/
void sort_decrescent(){}

int main_projeto(int argc, const char * argv[]) {

    char dadosC1[10][10] = {
            {'o'},
            {'O', 'l', 'a'},
            {'x', 'p', 't', 'o'},
            {'L', 'P'},
            {'1'},
            {'a', 'b', 'a'}
    };

    char dadosC2[10][10] = {
            {'b'},
            {'M', 'u', 'n', 'D', 'o'},
            {'P', 'L'},
            {'1', '1'}
    };

    int linhasC1 = 6;
    int colunasC1 = 10;
    int linhasC2 = 4;
    int colunasC2 = 10;
    char* valor = (char *) &dadosC1;

    //Criação da matrix c1
    char **DynamicMatrixC1 = (char **) create_Dynamic_Matrix(linhasC1, colunasC1);
    fill_Matrix(DynamicMatrixC1, linhasC1, colunasC1, dadosC1);

    //Criação da matrix c2
    char **DynamicMatrixC2 = create_Dynamic_Matrix(linhasC2, colunasC2);
    fill_Matrix(DynamicMatrixC2, linhasC2, colunasC2, dadosC2);

    // Imprimir as matrizes dinâmicas para teste
    printf("Matriz Dinâmica C1:\n");
    print_Matrix(DynamicMatrixC1, linhasC1, colunasC1);

    printf("\nMatriz Dinâmica C2:\n");
    print_Matrix(DynamicMatrixC2, linhasC2, colunasC2);

   /* teste decimal to binary e string to binary
    * decimal to binary com os numeros funciona bem, o string to binary não está a dar o
    * resultado esperado, por exemplo "aba" segundo o enunciado tem que dar:
    * 101010111010 , mas deu isto : 101010101111101010
    */

    decimal_to_binary(8);
    string_to_binary("a9A");

    add_to_matrix(DynamicMatrixC1, 3, 4, 4,5,valor);
   //  a usar notação array funciona, apontadores já não(nao sei porquê)
   free_Dynamic_Matrix(DynamicMatrixC1, linhasC1);
   free_Dynamic_Matrix(DynamicMatrixC2, linhasC2);

    return 0;
}
