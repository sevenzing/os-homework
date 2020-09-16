#!/bin/bash

# In my case race condition manifests itself 
# on 598th iteration (I saw 598 two times). 
# It happened because 2 processes read 
# the same number at the same time. 
# Critical region is `append_to_file` function call
# and line with `tail -n 1 $FILENAME.txt`

FILENAME=file

append_to_file(){
    echo $1 >> $FILENAME.txt
}


# initialize the file:
touch $FILENAME.txt

# If there is nothing in the file, then add 1
if [ $(cat $FILENAME.txt | wc -l) == 0 ]
then
    if ln $FILENAME.txt $FILENAME.lock 
    then
        append_to_file 1    
        rm $FILENAME.lock
    fi
fi


# Main loop. If lock file exist, just skip it
while true
do
    number=$(tail -n 1 $FILENAME.txt)
    if ln $FILENAME.txt $FILENAME.lock 
    then
        append_to_file $(($number + 1))    
        rm $FILENAME.lock
    fi 

done
