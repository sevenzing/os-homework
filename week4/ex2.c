#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]){
    int n = 5;

    for (int i = 0; i < n; i++){
        fork();
            
    }
    sleep(5);
    return 0;
}
