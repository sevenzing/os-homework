#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void print_dir(){
    char* username = getenv("USER");
    char* pwd = getenv("PWD");
    printf("%s: %s$ ", username, pwd);
}

int main(int argc, char const *argv[]){
    char user_input[2^16] = {};
    printf("Welcome to Innosh v2.0\n\n");
    
    while(strcmp(user_input, "exit\n")){
        print_dir();
        fgets(user_input, 2^16, stdin);
        int system_code = system(user_input);
    }
}
