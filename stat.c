#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void printHumanReadable(long long unsigned size) {
    int ctr = 0;
    long long unsigned sizeTemp = size;
    while (sizeTemp) {
        sizeTemp /= 10;
        ctr++;
    }
    ctr--;
    if (ctr < 3) {
        printf("%lluB", size);
    }
    else if (ctr < 6) {
        printf("%lluKB", size / 1000);
    }
    else if (ctr < 9) {
        printf("%lluMB", size / 1000000);
    }
    else {
        printf("%lluGB", size / 1000000000);
    }
}

void printLS(int mode, long long unsigned size, char * time) {
    //temp
    printf("--------");
    char timeformatted[strlen(time)];
    strncpy(timeformatted, time + 4, 12);
    printf(" 1 eccentricayman staff ");
    printHumanReadable(size);
    printf(" %s test.txt\n", timeformatted);
}

int main() {
    
    struct stat stats;
    stat("test.txt", &stats);
    printLS(stats.st_mode, stats.st_size, asctime(gmtime(&stats.st_atime)));
    return 0;
    
}
