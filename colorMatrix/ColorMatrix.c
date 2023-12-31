#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
struct Matrix {
    int rows;
    int cols;
    int** matrix; // Ponteiro para um array de ponteiros (matriz dinâmica)
};
struct Cord {
  int x;
  int y;
};

void delay(int seconds) {
    sleep(seconds);
}
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
        int numero_aleatorio = rand() % 2;
        newMatrix->matrix[i][j] = numero_aleatorio;
        
        
  }
  }
  return newMatrix;

}
int showMatrix(struct Matrix *matrix, int selectedNumber){
  system("clear");
  for (int j = 0; j < matrix->cols; j++) {
   for (int i = 0; i < matrix->rows; i++) {
                
        int cel = matrix->matrix[i][j];
      if(cel == selectedNumber)        
      printf("\033[32m %d \033[0m|", cel);
      else
      printf("\033[31m %d \033[0m|",cel);    
  }
   
    
      printf("\n \033[33m ----------------------------------------- \033[0m\n");
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
  if (*lista == NULL){
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
            printf("Erro: Falha na alocação de memória.\n");
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
    if(cord->x+1 < matrix->cols){
    if(matrix->matrix[cord->x+1][cord->y] == colorToChange){
      push(&lista, &tamanho, cord->x+1, cord->y);      
    }
    }
    if(cord->x-1 >= -1){
     if(matrix->matrix[cord->x-1][cord->y] == colorToChange){
      push(&lista, &tamanho, cord->x-1, cord->y);      
    }              

    }
   if(cord->y+1 < matrix->rows){
    if(matrix->matrix[cord->x][cord->y+1] == colorToChange){
      push(&lista, &tamanho, cord->x, cord->y+1);      
    }              

    }
    if(cord->y-1 >= 0){
    if(matrix->matrix[cord->x][cord->y-1] == colorToChange){
      push(&lista, &tamanho, cord->x, cord->y-1);
    }
    }
    
    matrix->matrix[cord->x][cord->y] = newColor;
    popFirst(&lista, &tamanho);
    delay(1);
    showMatrix(matrix, newColor);
  }
}
int main(){
  int rows = 10;
  int cols = 10;
  struct Matrix* myMatrix = CreateMatrix(rows, cols); 

  showMatrix(myMatrix, 7);
  changeColor(myMatrix,7, 5, 5);  

}
