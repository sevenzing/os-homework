#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]){
    int n;
    n = fork();
    if (n != 0){
        printf("Hello from parent [PID = %d]\n", getpid());
    }
    else{
        printf("Hello from children [PID = %d]\n", getpid());
    }
    return 0;
}
