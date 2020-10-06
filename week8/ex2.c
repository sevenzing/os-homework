#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
    int ONE_MEGABYTE = 1024 * 1024;
    int amount_to_allocate = 1000 * ONE_MEGABYTE;
    for (int i = 0; i < 10; i++){
        char *a = malloc(amount_to_allocate);
        memset(a, 0, amount_to_allocate);
        sleep(1);
    }
    
    return 0;
}

/*
From the man 
si: Amount of memory swapped in from disk (/s).
so: Amount of memory swapped to disk (/s).

si so starts increasing when page swapping starts
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 3  0      0 1865408 1360392 4379024    0    0     0     0 12963 13763 10  7 84  0  0
 0  0      0 839288 1360392 4379012    0    0     0     0 12992 15012  9  8 83  0  0
 2  0      0 801236 1360392 4378500    0    0     0     0 12967 14805  6  4 90  0  0
 0  0   1024 192048 1354520 4014564    0  556   288  1040 13398 14774 10 12 78  0  0 <-- swpd become non zero.
 2  0   2816 171260 1257468 3139744   32 1220   524  1220 13181 14161 10 14 76  0  0
 2  0   2816 181984 1250984 3105548    0    4  1184     4 12946 13469 11  5 84  0  0
 0  0  10752 167788 955764 2434292    0 8104     4  8104 13332 14285 10 12 78  0  0
 3  0  19456 137840 526088 1904332   48 8436   180  8436 13752 15498  9 15 77  0  0
 0  0  19968 237064 494584 1827084   28  428  6472   480 13409 14482 12  6 82  1  0
 1  0  31488 231676  41396 1256620   32 11624 13962 11788 16174 15596  9 15 76  1  0
 2  0  31488 10463748  45212 1275216    0    0 21668     0 13682 15220  9  9 80  1  0
*/