# OSTEP
This repo includes sample codes in Operating Systems Three Easy Pieces written by Remzi and Andrea at UW-Madison.

I made slight modification to some of the codes so that it could pass compilation.

Sample code: hello_world.c
```
/*
  page number on OSTEP
  $ gcc -o hello_world hello_world.c -Wall -Werror (compile)
  $ ./hello_world (execute)
*/

#include <stdio.h>

int
main(int argc, char* argv[])
{
  // some comments...
  printf("Hello World.\n");
  return 0;
}

/*
  Some other explanations...
*/
```
