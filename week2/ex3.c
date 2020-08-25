#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    sscanf(argv[1], "%d", &n);
    int w = 2 * n - 1;

    for (int i = 1; i <= n; i++){
        // left spaces 
        for (int left_iter = 0; left_iter < n - i; left_iter++){
            printf(" ");
        }

        // stars
        for (int stars_iter = 0; stars_iter < 2 * i - 1; stars_iter++){
            printf("*");
        }

        // right spaces 
        for (int right_iter = 0; right_iter < n - i; right_iter++){
            printf(" ");
        }
        
        // end of a line
        printf("\n");
        
    }
    
        
    return 0;
}
