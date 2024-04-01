
#!/bin/bash

IP=$(ifconfig wlo1 | grep 'inet ' | awk '{print $2}')

if [ -z "$IP" ]; then
    echo "IP address for wlo1 not found"
    exit 1
fi

echo $IP
