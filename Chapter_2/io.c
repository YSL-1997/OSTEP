/*
  page 11
  $ gcc -o threads threads.c -Wall -Werror -pthread
  $ ./threads 1000
  $ ./threads 100000
*/

#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

int
main(int argc, char* argv[])
{
  /* 
    int open(const char *pathname, int flags, mode_t mode);
    
    return value: file descriptor on success
                  -1 on failure
    flags: must include one of the access modes: O_RDONLY, O_WRONLY, O_RDWR
                                                  R only   W only    R/W
    O_WRONLY - the file is write only.
    O_CREAT  - if pathname doesn't exist, create it as a regular file.
    O_TRUNC  - if the file already exists and is a regular file and the access 
               mode allows writing, it will be truncated to length 0 (overwrite)
    S_IRWXU  - user (file owner) has read, write, and execute permission.
  */
  int fd = open("./file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  assert(fd > -1); // fd of stdin is 0

  /* 
    ssize_t write(int fd, const void *buf, size_t count);
    
    write() writes up to count bytes from the buffer starting at buf to the file 
    referred to by the file descriptor fd.

    return value: the number of bytes written on success
                  -1 on failure
  */
  char* str = "hello world\n"; // strlen(str) = 12

  int rc = write(fd, str, 13); // 13 == len(str) + 1
  assert(rc == 13);

  close(fd);
  return 0;
}