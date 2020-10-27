#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#define FILENAME_OUT "ex1.txt"
#define FILENAME_IN "ex1.memcpy.txt"

int main () {
    // let me assume that FILENAME_OUT and FILENAME_IN already created.
    
    // open 2 files
    int fildes_out = open(FILENAME_OUT, O_RDWR);
    int fildes_in = open(FILENAME_IN, O_RDWR);

    // get size of file
    struct stat buffer; fstat(fildes_out, &buffer); int file_size = buffer.st_size;

    // trunc out file
    ftruncate(fildes_in, file_size);

    // place files into memory
    char *string_out_at_memory = mmap(NULL, file_size, PROT_READ, MAP_SHARED, fildes_out, 0);
    char *string_in_at_memory = mmap(NULL, file_size, PROT_WRITE, MAP_SHARED, fildes_in, 0);

    // copy content ousing memcpy
    memcpy(string_in_at_memory, string_out_at_memory, file_size);
    
    // unmap memory
    munmap(string_in_at_memory, file_size);
    munmap(string_out_at_memory, file_size);
    
    // close files
    close(fildes_out);
    close(fildes_in);


    return 0;
}