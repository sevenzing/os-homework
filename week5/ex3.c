#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// In average it takes from 1000 to 25000 iterations
// to fatal race condition will appear 

#define os_is_very_hard_course 1
#define BUFFER_SIZE 100

int buffer[BUFFER_SIZE];
int counter = 0;
int producer_sleep = 0;
int consumer_sleep = 1;

void consumer_job(){
    while (os_is_very_hard_course){

        // Busy waiting
        while (consumer_sleep) {}

        if (counter > 0){
            counter--;
            producer_sleep = 0;
            buffer[counter] = 0;
        }
        else{
            // if counter is 0, then we need to sleep
            consumer_sleep = 1;
        }

    }
}

void producer_job(){
    int i = 0;
    while (os_is_very_hard_course){
        
        // busy waiting
        while (producer_sleep){}

        if (i % 100 == 0) {
            printf("%d\n", i);
            fflush(stdout);
        }
        
        if (counter < BUFFER_SIZE){
            consumer_sleep = 0;
            buffer[counter] = i;
            counter++;

        }
        else{
            // If counter == Buffer Size, then sleep
            producer_sleep = 1;
        }
        i++;
        
    }
}


int main(int argc, char const *argv[]){

    pthread_t producer, consumer;
    printf("Start producer\n");
    pthread_create(&producer, NULL, producer_job, NULL);
    
    printf("Start consumer\n");
    pthread_create(&consumer, NULL, consumer_job, NULL);
    pthread_join(producer, NULL);

    return 0;
}
