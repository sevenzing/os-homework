#include <stdio.h>

int main(int argc, char const *argv[]) {
    char input_str[1000] = "";
    scanf("%s", input_str);
    int n = strlen(input_str);
    for (int i = n - 1; i >= 0; i--){
         printf("%c", input_str[i]);
    }
    
    return 0;
}
