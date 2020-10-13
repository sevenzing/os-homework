#include <stdio.h>
#include <stdlib.h>
/*
N = 10: 0.007992
N = 50: 0.053946
N = 100: 0.097902
*/

#define N 3 // amount of page frames
#define CLOCK_INTERVAL 3 // clock interrupt
#define MAX_AGE_SIZE 1 << 23 // size of counter

typedef unsigned int uint;

struct page_frame{
    
    uint page_number;

    // refenced bit
    uint r;

    // age of frame
    uint age;
    
    // present/absent bit
    // 0 - absent
    // 1 - present
    uint present; 
};

struct page_frame frames[N];

int main(int argc, char const *argv[])
{
    
    for (int i = 0; i < N; i++){
        frames[i].age = 0;
        frames[i].r = 0;
        frames[i].page_number = 0;
        frames[i].present = 0;
    }
    int hit = 0;
    int miss = 0;
    int clock_tick = 0;

    FILE *in = fopen("input.txt", "r");
    
    while (! feof(in)){
        int request_page;
    
        fscanf(in, "%d", &request_page);
        
        int found_page_id = -1;
        int to_replace_page_id = 0;

        for (int i = 0; i < N; i++){
            // if we found the page 
            if (frames[i].page_number == request_page && frames[i].present){
                found_page_id = i; // we found page
                frames[i].r = 1; // reference the page
                
                break; // we do not need to search
            }

            else if (!frames[i].present){
                to_replace_page_id = i; // we found not present page. 
                break; // no need to search further
            }

            else if (frames[i].age < frames[to_replace_page_id].age){
                to_replace_page_id = i; // found less requestable page
            }

        }

        if (found_page_id != -1){ // if we found page in table
            printf("hit! request_page: %d\n", request_page);
            hit++; // we got a hit!
            frames[found_page_id].r = 1;

        }
        else { // if did't find page in table
            printf("miss! request_page: %d, replacing %d with page %d with age %d\n", request_page, to_replace_page_id, frames[to_replace_page_id].page_number, frames[to_replace_page_id].age);
            miss++; // we got a miss :(

            // delete page from the table in insert request_page 
            frames[to_replace_page_id].page_number = request_page;
            frames[to_replace_page_id].present = 1;
            frames[to_replace_page_id].r = 1;
            frames[to_replace_page_id].age = MAX_AGE_SIZE;
        }
        
        if (!(clock_tick % CLOCK_INTERVAL)) {
            for (int i = 0; i < N; i++){
                frames[i].age >>= 1; // divide by 2
                if (frames[i].r){
                    frames[i].age |= MAX_AGE_SIZE; // set `first` bit to one
                }
                frames[i].r = 0; // dereference   
            }
        }

        clock_tick++;
    }
    
    printf("result: hits/(misses+hits) = %f\n ", (double)hit / (hit+miss));
    return 0;
}
