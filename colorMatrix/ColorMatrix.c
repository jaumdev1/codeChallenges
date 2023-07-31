#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Matrix {
    int rows;
    int cols;
    int** matrix; // Ponteiro para um array de ponteiros (matriz dinâmica)
};

struct Matrix* CreateMatrix(int rows, int cols){
struct Matrix* newMatrix = (struct Matrix*)malloc(sizeof(struct Matrix));
  if (newMatrix == NULL) {
       printf("Erro: falha na alocação de memória para a estrutura Matrix.\n");
        return NULL;
  }

  newMatrix->rows = rows;
  newMatrix->cols = cols;

newMatrix->matrix = (int**)malloc(rows * sizeof(int*));

    if (newMatrix->matrix == NULL) {
        printf("Erro: falha na alocação de memória para as linhas da matriz.\n");
        free(newMatrix);
        return NULL;
    }
  for (int i = 0; i < rows; i++) {
  
    newMatrix->matrix[i] = (int*)malloc(cols * sizeof(int));

        if (newMatrix->matrix[i] == NULL) {
          
            printf("Erro: falha na alocação de memória para as colunas da matriz.\n");
            for (int j = 0; j < i; j++) {
                free(newMatrix->matrix[j]); 
            }
            free(newMatrix->matrix); 
            free(newMatrix); 
            return NULL;
        }
  }

    return newMatrix;

}
int showMatrix(struct Matrix *matrix){

   for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
        
        int cel = matrix->matrix[i][j];
        printf(" %d |", cel);
        
  }
   int sizeBarra = matrix->cols*4;
   char barra[sizeBarra]; 
    for (int i = 0; i < sizeBarra; i++) {
        barra[i] = '-';
    }

    barra[(matrix->rows*4)] = '\0'; 

    printf("\n>%s<\n", barra);

}
}
int main(){
  int rows = 5;
  int cols = 5;
  struct Matrix* myMatrix = CreateMatrix(rows, cols); 
  showMatrix(myMatrix);
}
