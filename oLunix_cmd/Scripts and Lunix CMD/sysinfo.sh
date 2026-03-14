# NOT: {!/bin/bash}

# Store hostname
HOSTNAME=$(hostname)
# HOSTNAME is variable, and $() is placeholder for incoming output and hostname is your machine name

#----------------------------------------------------------------

# 3️⃣ Getting IP address
#? This line looks scary, but it’s just piping commands.
IP_ADDRESS=$(hostname -I | awk '{print $1}')

# pipe (|) is used to Sends output of one command to another
# awk is a text-processing tool
# {print $1} means “print the first column”


#----------------------------------------------------------------

USERNAME=$(whoami)



echo "Hostname  : $HOSTNAME"
echo "IP Address: $IP_ADDRESS"
echo "Username  : $USERNAME"
