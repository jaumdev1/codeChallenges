#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct Iterator Iterator;

typedef struct Iterator {
    void *data;
    size_t element_size;
    size_t num_elements;
    size_t current_index;
    void (*operation)(Iterator *);
};

void increment_operation(Iterator *iter) {
    iter->current_index++;
}

void decrement_operation(Iterator *iter) {
    iter->current_index--;
}

Iterator *iterator_forward(void *array, size_t array_length, size_t element_size) {
    Iterator *iter = (Iterator *)malloc(sizeof(Iterator));
    if (!iter) {
        return NULL; // Erro na alocação de memória
    }
    
    iter->data = array;
    iter->element_size = element_size;
    iter->num_elements = array_length;
    iter->current_index = 0;
    iter->operation = increment_operation;
    
    return iter;
}

Iterator *iterator_reverse(void *array, size_t array_length, size_t element_size) {
    Iterator *iter = (Iterator *)malloc(sizeof(Iterator));
    if (!iter) {
        return NULL; // Erro na alocação de memória
    }
    
    iter->data = array;
    iter->element_size = element_size;
    iter->num_elements = array_length;
    iter->current_index = array_length - 1;
    iter->operation = decrement_operation;
    
    return iter;
}

void *next(Iterator *iter) {
    if (iter->current_index < iter->num_elements && iter->current_index >= 0) {
        void *element = (char *)iter->data + iter->current_index * iter->element_size;
        iter->operation(iter);
        return element;
    } else {
        return NULL; // Fim da iteração
    }
}

int main() {
    int array[] = {1, 2, 3, 4};
    size_t num_elements = sizeof(array) / sizeof(array[0]);

    Iterator *iter = iterator_forward(array, num_elements, sizeof(int));
    Iterator *iterReverse = iterator_reverse(array, num_elements, sizeof(int));
    if (iter == NULL) {
        printf("Erro na criação do iterador.\n");
        return 1;
    }

     void *element;
    while ((element = next(iter)) != NULL) {
        int *value = (int *)element;
        printf("%d ", *value);
    }
     void *elementReverse;
    while ((elementReverse = next(iterReverse)) != NULL) {
        int *value = (int *)elementReverse;
        printf("Reverse: %d ", *value);
    }

   
    free(iter);

    return 0;
}

