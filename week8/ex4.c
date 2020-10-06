#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int ONE_MEGABYTE = 1024 * 1024;
    int amount_to_allocate = 1000 * ONE_MEGABYTE;
    
    for (int i = 0; i < 10; i++) {
        char *a = malloc(amount_to_allocate);
        memset(a, 0, amount_to_allocate);
        
        // create r variable
        struct rusage *r = malloc(sizeof(struct rusage));
        
        // store resource usage in r variable
        getrusage(RUSAGE_SELF, r);
        
        printf("ru_maxrss: %ld\tru_minflt: %ld\n", r->ru_maxrss, r->ru_minflt);
        sleep(1);
    }

    return 0;
}

/*
Output of $ gcc ex4.c -o ex4.out ; ./ex4.out

ru_maxrss: 6145240      ru_minflt: 1536106
ru_maxrss: 8193352      ru_minflt: 2048107
ru_maxrss: 10241464     ru_minflt: 2560108
ru_maxrss: 12289312     ru_minflt: 3072109
ru_maxrss: 2048984      ru_minflt: 512099
ru_maxrss: 4097324      ru_minflt: 1024104
ru_maxrss: 6145172      ru_minflt: 1536105
ru_maxrss: 8193284      ru_minflt: 2048106
ru_maxrss: 10241396     ru_minflt: 2560107
ru_maxrss: 12289236     ru_minflt: 3072108
*/