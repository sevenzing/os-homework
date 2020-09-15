#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define N 3

void print_hello_world(int id) {
    printf("Greetings from thread #%d\n", id);
    printf("Delete thread #%d\n", id);
    pthread_exit(NULL);
}


int main(int argc, char const *argv[]){
    int n = N;
    pthread_t threads[N];

    for (int i = 0; i < n; i++){
        
        printf("Create new thread #%d\n", i);
        pthread_t created_thread = threads[i];
        int status = pthread_create(&created_thread, NULL, print_hello_world, i);
        pthread_join(created_thread,  NULL);
    }
    
    return 0;
}


