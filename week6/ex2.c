#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void swap(int** a, int **b){
    int* temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void buble_sort(int** array, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            
            if (array[i][0] < array[j][0])
                swap(&(array[i]), &(array[j]));
        }
        
    }
    
}

int shortest_job_first(int **array, int *processed, int size, int t){
    // Returns index of next process to be execute

    int min_burst_time_index = -1;
    int min_burst_time = 100000000;
    for (int j = 0; j < size; j++){
        if (processed[j] || array[j][0] > t)
            continue;
        
        if (array[j][1] < min_burst_time){
            min_burst_time = array[j][1];
            min_burst_time_index = j;
        }
    }
    if (min_burst_time_index != -1)
        processed[min_burst_time_index] = 1;
    return min_burst_time_index;
}




int main(int argc, char const *argv[]){
    FILE *fptr;
    fptr = fopen("ex2.txt","r");
    int N;
    
    fscanf(fptr,"%d", &N);
    
    int **array = malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++){
        array[i] = malloc(2 * sizeof(int));
        fscanf(fptr, "%d %d", &array[i][0], &array[i][1]);

    }
    
    buble_sort(array, N);

    int t = 0;
    int turnaround_time_sum = 0;
    int waiting_time_sum = 0;
    int *processed = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        int next_process_index = shortest_job_first(array, processed, N, t);
        if (next_process_index < 0){
            t += 1;
            i -= 1;
            continue;
        }
        int arravial_time = array[next_process_index][0];
        int burst_time = array[next_process_index][1];
        
        t += burst_time;
        int turnaround_time = t - arravial_time;
        int waiting_time = turnaround_time - burst_time;
        
        turnaround_time_sum += turnaround_time;
        waiting_time_sum += waiting_time;
        
        printf("P%d(%d, %d):\tExit time: %d\tTurnaround time:%d\tWaiting time:%d\n", i, arravial_time, burst_time, t, turnaround_time, waiting_time);
        
    }

    int time = 0;
    printf("\nAverage Turnaround time: %f\tAverage waiting time: %f\n", turnaround_time_sum/(double)N, waiting_time_sum/(double)N);
    

    return 0;
}
