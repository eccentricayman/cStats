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
        printf("%llu B", size);
    }
    else if (ctr < 6) {
        printf("%llu KB", size / 1000);
    }
    else if (ctr < 9) {
        printf("%llu MB", size / 1000000);
    }
    else {
        printf("%llu GB", size / 1000000000);
    }
}

int main() {
    
    struct stat stats;
    stat("test.txt", &stats);
    printHumanReadable(stats.st_size);
    printf("mode: %O\n", stats.st_mode);
    printf("last access time: %s\n", asctime(gmtime(&stats.st_atime)));

    return 0;
    
}
