#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){
  DIR *dir = NULL;
  struct dirent *entry;
  struct stat file;

  dir = opendir(".");

  if(dir == NULL){
    printf("No Directory Present\n");
    return 101;
  }

  int i = 0;
  printf("Directory Contents >");
  while( (entry = readdir(dir)) != NULL){
    i++;
    stat(entry->d_name, &file);
    printf("Content %d: [%s] [%ld]\n", i, entry->d_name, file.st_size);
  }
}

