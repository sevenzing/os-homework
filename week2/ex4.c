#include <stdio.h>

void swap(int *a, int *b){
    // GUYS, HELP ME!
    // I'M STUCK IN THE VIM EDITOR!!!
    // HOW CAN I GET OUT??
    // CTRL + C DOEST WORK!!!!!!!!!!!!!!!!!!!!!!
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[]) {
    int a, b;
    printf("Enter two number like a b\n");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Swaped variables: %d %d\n", a, b);
    

    return 0;
}
