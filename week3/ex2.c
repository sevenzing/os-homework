#include <stdio.h>

void swap(int *a, int *b){
    // Swap to integer numbers
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *a, int size){
    // Sort all elemtns in array from 0 to `size`
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size-i; j++){
            if (a[j] > a[j + 1]){
                swap(&a[j], &a[j + 1]);
            }
        }
        
    }}


int main(){
    int a[15] = {4,5,2,6,7,1,5,3,1,5,0,0,2,1};
    
    bubble_sort(a, 15);
    for (int i = 0; i < 15; i++){
        printf("%d ", a[i]);
    }
    return 0;
}