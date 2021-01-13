/*
  page 7
  $ gcc -o mem mem.c -Wall -Werror
  $ ./mem
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int
main(int argc, char* argv[])
{
  int* p = malloc(sizeof(int));
  assert(p != NULL);

  printf("pid: (%d) is pointed to by p, p's address: %p\n", getpid(), p);

  *p = 0;
  while(1){
    sleep(1);
    *p = *p + 1;
    printf("pid: (%d), value of what p points to: %d\n", getpid(), *p);
  }

  return 0;
}