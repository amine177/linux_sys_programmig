#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


int main(const int argc, const char* argv[static argc+1]) {

  int fd;
  int err;


  // Create file if it doesn't exist
  // with permission RWX for user, group and others
  fd = open(argv[1], O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
  if (fd == -1) {
    err = errno;
    fprintf(stderr, "can't create file %s [%s]: MAIN\n",
	    argv[1],
	    strerror(err));
    return EXIT_FAILURE;
  } else {
    fprintf(stdout, "created file %s: MAIN\n", argv[1]);
    return EXIT_SUCCESS;
  }
  return EXIT_SUCCESS;
}
