#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

int main() {
  char * filename = ".";
  DIR *dir;
  struct dirent *dir_entry;

  printf("Statistics for directory: %s\n", filename);

  int total_size = 0;
  dir = opendir(filename);
  while (dir_entry = readdir(dir))
    if (dir_entry->d_type == DT_REG) {
      struct stat file_buff;
      stat(dir_entry->d_name, &file_buff);
      total_size += (int)(file_buff.st_size);
    }
  closedir(dir);
  printf("Total Directory Size: %d\n", total_size);

  dir = opendir(filename);
  printf("Directories:\n");
  while (dir_entry = readdir(dir))
    if (dir_entry->d_type != DT_REG)
      printf("\t%s\n", dir_entry->d_name);
  closedir(dir);

  dir = opendir(filename);
  printf("Files:\n");
  while (dir_entry = readdir(dir))
    if (dir_entry->d_type == DT_REG)
      printf("\t%s\n", dir_entry->d_name);
  closedir(dir);  
  return 0;
}
