/*
  page 7
  $ gcc -o mem mem.c -Wall -Werror
  $ ./mem
  $ ./mem & $ ./mem &
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int
main(int argc, char* argv[])
{
  // malloc memory that pointed to by p
  int* p = malloc(sizeof(int));
  assert(p != NULL);
  *p = 0;

  printf("p  - address of what p points to: %p\n", p);
  printf("&p - address of p: %p\n", &p);
  printf("*p - value of what p points to: %d\n", *p);

  // pid - process identifier
  // p - address of the allocated memory
  printf("pid: (%d)\n", getpid());
  
  while(1){
    sleep(1);
    *p = *p + 1;
    printf("pid: (%d), value of what p points to: %d\n", getpid(), *p);
  }

  return 0;
}

/*
  The output is shown below:
  [1] 2531
  [2] 2532
  p  - address of what p points to: 0x5636ece502a0
  p  - address of what p points to: 0x55cdec80c2a0
  &p - address of p: 0x7fffc6e87e80
  &p - address of p: 0x7ffc62cbfe90
  *p - value of what p points to: 0
  *p - value of what p points to: 0
  pid: (2532)
  pid: (2531)
  pid: (2532), value of what p points to: 1
  pid: (2531), value of what p points to: 1
  pid: (2531), value of what p points to: 2
  pid: (2532), value of what p points to: 2
  pid: (2532), value of what p points to: 3
  pid: (2531), value of what p points to: 3

  In some cases, both programs may allocate the memory of the same address, 
  which is wired. This is because each running program has its own virtual 
  address space, which means address 0x1111 of pid 2531 is different from 
  0x1111 of pid 2532. 
*/