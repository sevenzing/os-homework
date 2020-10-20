#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#define N 255
#define ALREADY_PROCESSED -1488
int main(int argc, char const *argv[])
{
    DIR *dirp = opendir("tmp/");
    if (dirp == NULL){
        return -1;
    }

    int i_nums[N];
    char *file_names[N];
    
    struct dirent *Dir;
    
    int i = 0;
    while ((Dir = readdir(dirp)) != NULL) {
        // Запишем все значения которые мы нашли в массив
        i_nums[i] = Dir->d_ino;
        file_names[i] = Dir->d_name;
        i++;
    }

    int amount_of_dirs = i;
    for (int i = 0; i < amount_of_dirs; i++){
        int found = 0;
        for (int j = i + 1; j < amount_of_dirs; j++){
            // Если нашли два файла с одинаковым i_num
            if ((i_nums[i] == i_nums[j]) && (i_nums[j] != ALREADY_PROCESSED)){
                if (!found){
                    printf("I found several files with the same inum: %s %s", file_names[i], file_names[j]);
                    found = 1;
                }
                else{
                    printf(", %s", file_names[j]);
                }
                i_nums[j] = ALREADY_PROCESSED;

            }
        }

        if (found){
            printf("\n");
        }
        
    }
    
    closedir(dirp);
    return 0;
}
