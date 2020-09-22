#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int compare(int *process1, int *process2){
    int value;
    if (process1[5] != process2[5])
        // how many times it was executed
        value = process1[5] - process2[5];
    else
        // arravial time
        value = process1[0] - process2[0];
    return value;
}


void swap(int** a, int **b){
    int* temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void buble_sort(int** array, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){  
            if (compare(array[i], array[j]) < 0)
                swap(&(array[i]), &(array[j]));
        }

    }
    
}

int first_come_first_served(int **array, int size){
    // Returns index of next process to be execute
    buble_sort(array, size);
    for (int i = 0; i < size; i++){
        
        // if not finished
        if (!array[i][6]){
            array[i][6] = 1;

            // +1 # of execution
            array[i][5] += 1;
            return i;
        }
    }
    return size;
    
}


int main(int argc, char const *argv[]){
    FILE *fptr;
    fptr = fopen("ex3.txt","r");
    int N;
    int Quantum = 3;
    fscanf(fptr,"%d", &N);
    
    int **array = malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++){
        array[i] = malloc(7 * sizeof(int));
        fscanf(fptr, "%d %d", &array[i][0], &array[i][1]);
        array[i][2] = i;            // real name
        array[i][3] = array[i][0];  // real arravial time
        array[i][4] = array[i][1];  // real burst
        array[i][5] = 0;            // how many times it was executed
        array[i][6] = 0;            // finished
    }
    
    buble_sort(array, N);

    int t = 0;
    int turnaround_time_sum = 0;
    int waiting_time_sum = 0;
    
    for (int i = 0; i < N; i++){
        int next_process_index = first_come_first_served(array, N);
                
    
        int arravial_time = array[next_process_index][0];
        int burst_time = array[next_process_index][1];
        
        if (burst_time > Quantum){
            burst_time = Quantum;
            array[next_process_index][6] = 0; // not finished
            i -= 1;
            array[next_process_index][0] = t;
            array[next_process_index][1] -= Quantum;
        }
        
        t += burst_time;
        
        int turnaround_time = t - arravial_time; // [OK]
        int waiting_time = turnaround_time - burst_time; // [OK]
        
        turnaround_time_sum += turnaround_time;
        waiting_time_sum += waiting_time;
        
        int real_index = array[next_process_index][2];
        int real_arravial_time = array[next_process_index][3];
        int real_burst_time = array[next_process_index][4];

        printf("P%d(%d, %d):\tBurst time:%d\tExit time: %d\tTurnaround time:%d\tWaiting time:%d\n", real_index, real_arravial_time, real_burst_time, burst_time, t, turnaround_time, waiting_time);
        
    }

    int time = 0;
    printf("\nAverage Turnaround time: %f\tAverage waiting time: %f\n", turnaround_time_sum/(double)N, waiting_time_sum/(double)N);
    
    
    return 0;
}
