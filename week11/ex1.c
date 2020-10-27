#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>


int main () {
    int fd = open("ex1.txt", O_RDWR);

    char *new_content = "This is a nice day";
    int N = strlen(new_content);
    struct stat buffer;
    
    fstat(fd, &buffer); int real_file_size = buffer.st_size;


    char *string_for_file = mmap(NULL, N, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    memcpy(string_for_file, new_content, N);
    
    ftruncate(fd, N);
    munmap(string_for_file, N);
    close(fd);


    return 0;
}