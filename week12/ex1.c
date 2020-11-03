#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define N 20
int main() {
    // 
    int file_random_d = open("/dev/random", O_RDWR);

    // Give right 755 right in order to be able to open file
    int out_file_d = open("./ex1.txt", O_RDWR | O_CREAT, 0755);
    char string[N];
    // get string FROM file TO string
    read(file_random_d, string, N);

    // write string TO file FROM string
    write(out_file_d, string, N);

    // close files
    close(out_file_d); close(file_random_d);
}