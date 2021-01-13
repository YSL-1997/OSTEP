/*
  page 5
  $ gcc -o cpu simple_spin.c -Wall -Werror
  $ ./cpu A & ./cpu B & ./cpu C & ./cpu D &
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>

int
main(int argc, char* argv[])
{
  if(argc != 2){
    fprintf(stderr, "usage: cpu <string>\n");
    exit(1);
  }
  
  char* str = argv[1];

  while(1){
    sleep(1); // in OSTEP, it uses Spin(1), #include "common.h"
    printf("%s\n", str);
  }
  
  return 0;
}
