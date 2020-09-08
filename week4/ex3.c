#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]){
    char user_input[255] = {};
    printf("Welcome to Innosh\n\n");

    while(strcmp(user_input, "exit")){
        printf("$ ");
        scanf("%s", user_input);
        int system_code = system(user_input);
        printf("\n");
    }
}
