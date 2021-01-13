/*
  page 9
  $ gcc -o threads threads.c -Wall -Werror -pthread
  $ ./threads 1000
  $ ./threads 100000
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int counter = 0;
int loops;

void* worker(void* arg){
  for (int i = 0; i < loops; i++){
    counter++;
  }
  
  return NULL;
}

int
main(int argc, char* argv[])
{
  if(argc != 2){
    fprintf(stderr, "usage: threads <value>\n");
    exit(EXIT_FAILURE);
  }

  loops = atoi(argv[1]);
  pthread_t p1, p2;
  printf("counter initial value: %d\n", counter);

  // create 2 threads that running in a routine called worker()
  pthread_create(&p1, NULL, worker, NULL);
  pthread_create(&p2, NULL, worker, NULL);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  printf("counter final value  : %d\n", counter);
  return 0;
}

/*
  We expect to see the counter final value: 2N if we set loops = N. However, it
  is not what we actually saw when we set N to be a large number. Why?

  increment (i++): 3 steps
    load the value of counter from memory into register
    increment value of counter inside register
    store the value of counter back into memory
  The above three steps do not execute atomically (all at once)

  Say counter = 0, and thread p1 is now running.
  If p1 has just incremented counter (now, counter = 1) when an interrupt occurs
  (not yet write to memory, so in memory, counter is still 0), then p2 loads the 
  value (counter = 0) that has not yet been incremented into register. After p2
  does the increment (counter = 1) and writes back into memory, say an interrupt 
  occurs again, then p1 starts to run, and stores counter = 1 into memory.

  The above case has two increments, but counter only increments by 1.  
*/