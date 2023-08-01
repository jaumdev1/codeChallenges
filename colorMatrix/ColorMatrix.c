#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
struct Matrix {
    int rows;
    int cols;
    int** matrix; // Ponteiro para um array de ponteiros (matriz dinâmica)
};
struct Cord {
  int x;
  int y;
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
  srand(time(NULL));
  for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        int numero_aleatorio = rand() % 3;
        newMatrix->matrix[i][j] = numero_aleatorio;
        
        
  }
  }
  return newMatrix;

}
int showMatrix(struct Matrix *matrix){
   for (int j = 0; j < matrix->cols; j++) {
   for (int i = 0; i < matrix->rows; i++) {
                
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
void push(struct Cord** lista, int* tamanho, int novo_x, int novo_y) {

  struct Cord* novo_elemento = (struct Cord*)malloc(sizeof(struct Cord));
   if (novo_elemento == NULL) {
    printf(stderr, "Erro: Falha na alocação de memória.\n");
    exit(EXIT_FAILURE);
  }


  novo_elemento->x = novo_x;
  novo_elemento->y = novo_y;



  (*tamanho)++;
  *lista = (struct Cord*)realloc(*lista, (*tamanho) * sizeof(struct Cord));
  if (*lista == NULL) {
    fprintf(stderr, "Erro: Falha na alocação de memória.\n");
    exit(EXIT_FAILURE);
  }


  (*lista)[(*tamanho) - 1] = *novo_elemento;


  free(novo_elemento);
}


void popFirst(struct Cord** lista, int* tamanho) {
    if (*tamanho > 0) {
        for (int i = 0; i < (*tamanho) - 1; i++) {
            (*lista)[i] = (*lista)[i + 1];
        }
        (*tamanho)--;
        *lista = (struct Cord*)realloc(*lista, (*tamanho) * sizeof(struct Cord));
        if (*tamanho > 0 && *lista == NULL) {
            fprintf(stderr, "Erro: Falha na alocação de memória.\n");
            exit(EXIT_FAILURE);
        }
    }
}
void changeColor(struct Matrix *matrix, int newColor, int positionRow, int positionCol){
  int colorToChange = (matrix->matrix[positionRow][positionCol]);
  struct Cord* lista = NULL;
  int tamanho = 0;
  push(&lista, &tamanho, positionRow, positionCol);
  while(tamanho > 0){
    struct Cord *cord = &lista[0];
    printf("\nlistaX: %d \n", cord->x);
    if(cord->x+1 < matrix->matrix->cols){
      if(matrix->[cord->x+1][cord->y] == colorToChange){

      }

    }
    if(cord->x-1 > 0){

    }
    if(cord->y+1 < matrix->matrix->rows){

    }
    if(cord->y-1 < 0){

    }

    
    popFirst(&lista, &tamanho);
  }
}
int main(){
  int rows = 10;
  int cols = 10;
  struct Matrix* myMatrix = CreateMatrix(rows, cols); 
  showMatrix(myMatrix);
  changeColor(myMatrix,42, 5, 5);  
  showMatrix(myMatrix);
}
