// for open(), O_RDONLY, EXIT_FAILURE & EXIT_SUCCESS..
#include <stdlib.h>
#include <fcntl.h>
// for close()
#include <unistd.h>
// for fprintf()
#include <stdio.h>
// for strerror
#include <string.h>
// for errno
#include <errno.h>


int main(const int argc, const char* argv[static argc+1]) {

  // the file descriptor number of the file to open
  int fd;
  // open() the file named by argv[1] (first argument)
  // in readonly mode (O_RDONLY)
  fd = open(argv[1], O_RDONLY);
  // in case open failed, print the file name
  // and the error string corresponding to error number
  // reported by errno
  if (fd == -1) {
    // printf to the standard output fd of the program (stderr)
    fprintf(stderr,
	    "open %s failed [%s]: MAIN\n" ,
	    argv[1],
	    strerror(errno));
    // exit with failure
    return EXIT_FAILURE;
  } else {
    // report success of opening the file named by argv[1]
    fprintf(stdout, "open %s with fd %d success: MAIN\n",
	    argv[1],
	    fd);
    // close the file through its file descriptor
    close(fd);
  }
  // exit with success status
  return EXIT_SUCCESS;
}
