#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


int main() {
  DIR *directory = opendir(".");
  struct dirent *file = readdir(directory);
  int size = 0;
  struct stat sb;

  while (file){
    if (file->d_type == DT_REG){
      stat(file->d_name, &sb);
      size+=sb.st_size;
      printf("%s   %ld bytes\n", file->d_name, sb.st_size);
    }
    else {
      printf("> %s\n", file->d_name);
    }

    file = readdir(directory);
  }
  closedir(directory);

  printf("\nTotal Directory Size: %d\n",size);

  return 0;
}