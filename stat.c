#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  struct stat stats;
  stat("file", &stats);
  printf("Size: %d\n", stats.st_size);
  printf("Mode: %d\n", stats.st_mode);
  printf("Time: %d\n", stats.st_atime);
  return 0;
}
