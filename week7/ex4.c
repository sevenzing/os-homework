#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// 10
// mem copy with prev_size 40 and size 80
// 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 0 0 0 0 0

int min(int a,int b){
    return a > b ? b : a;
}

void *custom_realloc(void *ptr, int size){
    void *new = NULL;

    if (size > 0){
        int prev_size;
        if (ptr == NULL) {
            prev_size = 0;
        }
        
        else {
            prev_size = malloc_usable_size(ptr);
        }
        new = malloc(size);
        printf("mem copy with prev_size %d and size %d\n", prev_size, size);
        memcpy(new, ptr, min(prev_size, size));
    }

    free(ptr);
    return new;
}


int main(int argc, char const *argv[]){
    
    int N;

    scanf("%d", &N);

    int *array = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        array[i] = i;
    }

    array = custom_realloc(array, 2*N * sizeof(int));

    for (int i = 0; i < 2*N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}
    