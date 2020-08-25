#include <stdio.h>

int main(int argc, char const *argv[]) {
    int integer_number = __INT_MAX__;
    float float_number = __FLT_MAX__;
    double double_number = __DBL_MAX__;
    printf("Integer:\t%lu\t%d\n", sizeof(integer_number), integer_number);
    printf("Float  :\t%lu\t%f\n", sizeof(float_number), float_number);
    printf("Double :\t%lu\t%f\n", sizeof(double_number), double_number);

    return 0;
}
