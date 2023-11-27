/**
    * ==================================================================================================================
    * PROJETO REALIZADO POR:                                                                                           *
    * - PEDRO MARQUES - 38688                                                                                          *
    * - PEDRO MONTEIRO  - 2022110782                                                                                             *
    * - DIONE ARANTES - 40395                                                                                             *
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
#include <string.h>
#include "projeto.h"
#include "ctype.h"
#include <time.h>

#define NULL0 -1;
#define NUMROWS 10
#define NUMCOLS 7

DYNAMICMATRIX DynamicMatrix;
VAL_AD_WORDS_HOLDER val_Ad_Words_Holder;
NODE_LL_WORDS_HOLDER Node_Ll_Words_Holder;

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

void print_Matrix(char** matrix, int numRow, int numCollum) {
    for (int i = 0; i < numRow; i++) {
        for (int j = 0; j < numCollum; j++) {
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
void decimal_to_binary(int value, char **matriz, int line, int column) {
    //  printf("TESTE-> valor em decimal fica %d\n", value);
    //array com os valores de binario
    // counter for binary array

    printf("\nThe string in binary is ");

    int h = 0;
    char charvalue='\0';
    int binaryNum[8];
    while (value > 0) {
        // storing remainder in binary array
        binaryNum[h] = value % 2;
        value = value / 2;
        h++;
    }
    // printing binary array in reverse order
    for (int j = h - 1; j >= 0; j--, column++) {
        printf("%d", binaryNum[j]);
        charvalue = binaryNum[j]+'0';
        matriz[line][column] = charvalue;
    }
}

/** req 2 **/
void string_to_binary(char **matriz,int numpalavras) {
    /** a idea é pegar na string original
     * tirar o size
     * correr em loop e separar a string em diferentes char
     * enviar esse char para a funçao decimal_to_binary
     */
    for (int i = 0; i < numpalavras; i++) {

        int size = strlen(*(matriz + i));
        int g = 0;
        int value;

        for (int j = 0; j < size; j++) {
            value = matriz[i][j] - '0';
            if (isupper(matriz[i][j])) {
                value = value + 19;
                decimal_to_binary(value, matriz, i, g);
            } else if (value <= 9) {
                decimal_to_binary(value, matriz, i, g);
            } else {
                value = value - 39;
                decimal_to_binary(value, matriz, i, g);
            }
        }
        printf("\n");
    }
}

/*
 *
 * funlção para inserir os dados num char e uma nos binarios ou seja uma big função para 2 mini funções
 * função para chamar structs pois estas vao ter
void add_to_matrix(DYNAMICMATRIX *matrix, int row, int col, char value) {
    if (matrix != NULL && row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {
        *(*(matrix->data + row) + col) = value;
    } else {
        printf("Posição inválida na matriz.\n");
    }
}*/

char gerarPalavraAleatoria(char *palavra, int tamanho) {
    const char caracteresPermitidos[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int lenCaracteresPermitidos = strlen(caracteresPermitidos);

    for (int i = 0; i < tamanho - 1; i++) {
        palavra[i] = caracteresPermitidos[rand() % lenCaracteresPermitidos];
    }

    palavra[tamanho - 1] = '\0'; // Adicionar o char nulo no final
    printf(" %s", palavra);

    return *palavra;
}

/** req 3
 * aqui podemos definir onde colocamos os determinados valores dentro das matrizes
 * para teste primeiro damos print a matriz inicial e depois print com a insercao
 *
 * **/


    void add_to_matrix(char **Matrix1, int row, int collum, int numRow, int numCollum, const char *palavra) {
        if (row >= 0 && row < numRow && collum >= 0 && collum < numCollum) {
            *(*(Matrix1 + row) + collum) = *palavra;
            //string_to_binary(value);
            //print_Matrix(matrix, row,collum);
            //gerarPalavraAleatoria(palavra, 7);
            strncpy((*(Matrix1 + row) + collum), palavra, strlen(palavra));
        } else {
            printf("invalid insert\n");
        }
    }

/** req 3 **/
    void remove_from_matrix(DYNAMICMATRIX *matrix, int row, int col) {
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
            matrix->data = (char **) realloc(matrix->data, matrix->rows * sizeof(char *));
            for (int i = 0; i < matrix->rows; i++) {
                matrix->data[i] = (char *) realloc(matrix->data[i], matrix->cols * sizeof(char));
            }
        } else {
            printf("Posição inválida na matriz.\n");
        }
    }

/** req 4 **/
    void check_segment(char **matrix,char **matrix2) {
        int value = 1 ;
        for(int i=0;i<NUMROWS;i++) {
            for (int j = 0; j < NUMROWS;j++){
            value = strcmp(*(matrix+i),*(matrix2+j));
            if(value == 0){
                printf("%s %s são combinações iguais",*(matrix+i),*(matrix2+j));
                value = 1;
            }
          }
        }
    }

/** req 5 **/
    void seach_string(const char *sequencia, const char *palavra[], int numPalavras) {

        for (int i = 0; i < numPalavras; i++) {
            //Verifica se a sequência de pesquisa ocorre na palavra
            if (strstr(palavra[i], sequencia) != NULL) {
                printf("%s\n", palavra[i]);
            }
        }
    }

/** req 6 **/
void sort_crescent(int matriz[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = matriz[left + i];
    for (j = 0; j < n2; j++)
        R[j] = matriz[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            matriz[k] = L[i];
            i++;
        } else {
            matriz[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        matriz[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        matriz[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        sort_crescent(arr, left, middle, right);
        sort_decrescent(arr, left, right);
    }

}



/** req 6 **/
void sort_decrescent(int arr[], int left, int right) {
    mergeSort(arr, left, right);

    int i = left;
    int j = right;

    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

}




    int main_projeto(int argc, const char *argv[]) {

        srand(time(NULL)); //gera a aleatoriedade

        char dadosC1[10][10] = {
                {"o"},
                {"Ola"},
                {"xpto"},
                {"LP"},
                {"1"},
                {"aba"},
                {"fgagji9"}
        };

        char dadosC2[10][10] = {
                {"b"},
                {"MunDo"},
                {"PL"},
                {"11"}
        };


        int linhasC1 = 7;
        int colunasC1 = 7;
        int linhasC2 = 6;
        int colunasC2 = 10;
        char palavra[8];
        char *valor = (char *) &palavra;

        //Criação da matrix TESTE c1
        char **DynamicMatrixC1 = (char **) create_Dynamic_Matrix(linhasC1, colunasC1);
        fill_Matrix(DynamicMatrixC1, linhasC1, colunasC1, dadosC1);

        //Criação da matrix TESTE c2
        char **DynamicMatrixC2 = create_Dynamic_Matrix(linhasC2, colunasC2);
        fill_Matrix(DynamicMatrixC2, linhasC2, colunasC2, dadosC2);

        //Criação da matrix Matrix1
        char **Matrix1 = create_Dynamic_Matrix(linhasC1, colunasC1);
        fill_Matrix(Matrix1, linhasC1, colunasC1, dadosC1);

        //fill_Matrix(Matrix1, LINES, COLS, (char[10]) palavra);

        /** Imprimir as matrizes para teste
         *
         *  printf("Matriz Dinâmica C1:\n");
         *  print_Matrix(DynamicMatrixC1, linhasC1, colunasC1);
         *  printf("\nMatriz Dinâmica C2:\n");
         *  print_Matrix(DynamicMatrixC2, linhasC2, colunasC2);
         *
         */

        print_Matrix(Matrix1, linhasC1,colunasC1);

        /* teste decimal to binary e string to binary
         * decimal to binary com os numeros funciona bem, o string to binary não está a dar o
         * resultado esperado, por exemplo "aba" segundo o enunciado tem que dar:
         * 101010111010 , mas deu isto : 101010101111101010
         */

        // Exemplo de uso

       /* for(int j=0;j<7;j++){
            gerarPalavraAleatoria(palavra, 7);
            printf("\n");
            add_to_matrix(Matrix1, j, 0, 7, 20, valor);
        }*/
        print_Matrix(Matrix1, linhasC1,colunasC1);


        print_Matrix(DynamicMatrixC1, linhasC1,colunasC1);

        string_to_binary(DynamicMatrixC1,7);
        //string_to_binary(Matrix1);
        //add_to_matrix(DynamicMatrixC1, 3, 4, 4, 5, valor,palavra);
        // a usar notação array funciona, apontadores já não(nao sei porquê)
        /*
         * free_Dynamic_Matrix(DynamicMatrixC1, linhasC1);
         * free_Dynamic_Matrix(DynamicMatrixC2, linhasC2);
         */
        print_Matrix(DynamicMatrixC1, linhasC1,colunasC1);
        return 0;
    }
