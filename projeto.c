#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "projeto.h"

#define NULL0 -1;

EX ex;

char * UFP6 = {
        //0    1     2    3      4     5        6     7      8       9       a       b        c      d       e        f       g        h         i        j         k        l       m        n        o       p         q       r        s         t        u        v        w          x         y           z
        "0", "1", "10", "11", "100", "101", "110", "111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111", "10000", "10001 ", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111", "100000", "100001", "100010", "100011"
};


int main_projeto(int argc, const char * argv[]){

    /**
     * req 1 - criar duas matrizes para os conjunto de palavras e um array com a representaçao binaria
     * N1 e N2 define o tamanho de cada matriz, pode ser igual ou nao e pode-se manipular este valor
     */
/*
    char c1 [10][10] = {
            {'o'},
            {'O', 'l', 'a'},
            {'x', 'p', 't', 'o'},
            {'L', 'P'},
            {'1'},
            {'a', 'b', 'a'}
    };

    char c2 [10][10] = {
            {'b'},
            {'M', 'u', 'n', 'D', 'o'},
            {'P', 'L'},
            {'1', '1'}
    };
    */




    int numRows = 10;
    int numCollums = 10;


    /** criar uma funçao que passa-se como parametro a string que queremos colocar
     * da separar a string, char a char e adicionar esses char numa coluna, posição a posição
     * fazer isto de forma recursiva para introduzir valoes dentro da matriz de forma facil
     * ver adicionar na matriz implementação
     * ver como dividir uma string em char
     */

    /**
     * todo
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
     */

    int value = 97;
    char * string  =  "aaa";

    printf("the original value -> %d\n", value);
    decimal_to_binary(value);
    printf("\n");

    printf("the original value -> %s\n", string);
    string_to_binary(string);

    //aloca memoria para a criação da matriz
    char **matrix = (char **)  malloc(numRows * sizeof(int *));
    create_matrix(numRows, numCollums, matrix);


    char hello [] = "X";
    /**print da matriz inicial**/

   // printf("Original matrix\n\n");
  //  print_matrix(matrix);


    printf("value to insert -> %s\n", hello);
    add_to_matrix(matrix, 2,4, 10, 10, hello);
    print_matrix(matrix);


   /*
    printf("Matrix after insert\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <10 ; ++j) {
            printf("%c\t", matrix[i][j]);
        }
        printf("\n");
    */

   // a[i][j] = ((a[i]) a[j])


  //  remove_from_matrix(matrix, 2, 4, 10, 10);
  //  print_matrix(matrix);
    /*
    printf("Matrix after remove\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <10 ; ++j) {
            printf("%c\t", matrix[i][j]);
        }
        printf("\n");
    }
     */

    //após usar os valores libertamos a memoria usada para a matriz
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCollums; ++j) {
            free(matrix[j]);
        }
        free(matrix[i]);
    }
    free(matrix);

        return 0;
}

/** para ja deixar como parametro row e collum mas depois fazer com macros **/
char * create_matrix(int numRows, int numCollums, char ** matrix){

    /** criação da matriz por memoria dinamica**/

    //aloca memoria para a criação da matriz
    //char **matrix = (char **)  malloc(numRows * sizeof(int *));

    //perante o numero de filas, alocamos memoria para as colunas
    for (int i = 0; i < numRows; i++) {
        //com realloc, ajustar o valor necessário para todas as colunas
        matrix[i] = (char *) malloc(numCollums * sizeof(int));
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCollums; ++j) {
            /**alocamos memoria para cada valor, e determinado Null para o fim de cada string
             * depois disso passamos os valores definidos antes para aqui
             * podera haver uma outra forma de inicializar as matrizes
             */
            //  matrix[i][j] = (char *)malloc(2 * sizeof(char));
            //  matrix[i][j] = c1[i][j];
            //iniciar a zero
            matrix[i][j] = NULL0;
        }
    }


}





void print_matrix(char ** matrix){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <10 ; ++j) {
            printf("%c\t", matrix[i][j]);
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
int decimal_to_binary(int value){
  //  printf("TESTE-> valor em decimal fica %d\n", value);
    //array com os valores de binario
    int binary[32];
    int i;
    for ( i = 0; value > 0; i++) {
        // storing remainder in binary array
        binary[i] = value % 2;
        value = value / 2;
    }

  //  printf("the value in binary -> ");
    for ( i = i - 1; i >= 0; i--){
        printf("%d", binary[i]);
    }
   // printf("\n");
    return 0;

}

/** req 2 **/
int string_to_binary(char * string){

    /** a idea é pegar na string original
     * tirar o size
     * correr em loop e separar a string em diferentes char
     * enviar esse char para a funçao decimal_to_binary
     */

    int size = strlen(string);

    printf("The string in binary is ");
    for (int i = 0; i < size; i++) {

       printf("%d ", decimal_to_binary(string[i])) ;
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
        matrix[row][collum] = *value;
        string_to_binary(value);
    }
    else{
        printf("invalid insert\n");
    }
}

/** req 3 **/
void remove_from_matrix(char ** matrix, int row, int collum, int numRow, int numCollum){
    if(row >=0 && row < numRow && collum >=0 && collum < numCollum){
        printf("Value deleted -> %c\n", matrix[row][collum]);
        string_to_binary(&matrix[row][collum]);
        matrix[row][collum] = NULL0;
    }
    else{
        printf("invalid insert\n");
    }
}

/** req 4 **/
void check_segment(char segment){}

/** req 5 **/
void seach_string(char string){}

/** req 6 **/
void sort_crescent(){}

/** req 6 **/
void sort_decrescent(){}