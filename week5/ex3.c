#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1
int producer_sleep = 0;
int consumer_sleep = 1;

void consumer_job(int *buffer){
    while (1){
        if (!consumer_sleep){
            printf("Consumer: start consuming. First value of buffer is %d\n", buffer[0]);
            if (buffer[0] != 1){
                printf("Consumer: press F to pay respect");
                fflush(stdout);
            }
            fflush(stdout);
            
            for (int i = 0; i < BUFFER_SIZE; i++){
                buffer[i] = 0;
            }
            
            printf("Consumer: consumed buffer!\n");
            consumer_sleep = 1;
            producer_sleep = 0;
            fflush(stdout);
        }
        else{
            printf("Consumer: Sleeeeeeeeeeep...\n");
            sleep(1);
            fflush(stdout);
        }
    }
}

void producer_job(int *buffer){
    while (1){
        if (!producer_sleep){
            printf("Producer: start producing. First value of buffer is %d\n", buffer[0]);
            fflush(stdout);
            if (buffer[0] != 0){
                printf("Producer: press F to pay respect");
                fflush(stdout);
            }
            for (int i = 0; i < BUFFER_SIZE; i++){
                buffer[i] = 1;
            }
            
            printf("Producer: produced buffer!\n");
            consumer_sleep = 0;
            producer_sleep = 1;
            fflush(stdout);
        }
        else{
            printf("Producer: Sleeeeeeeeeeep...\n");
            sleep(1);
            fflush(stdout);
        }
    }
}


int main(int argc, char const *argv[]){
    
    int *buffer = malloc(BUFFER_SIZE);

    pthread_t producer, consumer;
    printf("Start producer\n");
    pthread_create(&producer, NULL, producer_job, buffer);
    
    printf("Start consumer\n");
    pthread_create(&consumer, NULL, consumer_job, buffer);
    pthread_join(consumer, NULL);

    return 0;
}
