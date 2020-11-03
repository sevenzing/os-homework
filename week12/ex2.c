#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>


int main(int argc, char **argv){
    int append = 0;
    int N = argc - 1;
    if (argc <= 1) {
        // handle error
        return 137;
    }

    if (strcmp(argv[1], "-a") == 0) {
        append = 1;
        N -= 1;
    }

    int *files_d = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        // create file if not exists, append to the file if -a flag exists
        files_d[i] = open(argv[i + 1 + append], (O_APPEND * append) | O_CREAT | O_RDWR, 0644);
    }
    
    char string;

    // zero means STDIN
    while (read(0, &string, 1) != 0){
        // Write to the files
        for (int i = 0; i < N; i++) {
            write(files_d[i], &string, 1);
        }
        
        // Write to the STDOUT (ONE)
        printf("%c", string);
    }
    
    for (int i = 0; i < N; i++) {
        close(files_d[i]);
    }
    
    
}