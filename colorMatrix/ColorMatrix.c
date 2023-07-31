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
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        int numero_aleatorio = rand() % 2; 
        newMatrix->matrix[i][j] = numero_aleatorio;
        }
    }

    return newMatrix;

}
int showMatrix(struct Matrix *matrix){

   for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
        
        int cel = matrix->matrix[i][j];
        printf(" %d |", cel);
          printf("_____");
        }
    }

}
int main(){
  int rows = 5;
  int cols = 5;
  struct Matrix* myMatrix = CreateMatrix(rows, cols);
  showMatrix(myMatrix);

}
