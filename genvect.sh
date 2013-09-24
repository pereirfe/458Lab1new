#!/bin/bash

SIZE=20
INCR=20
FILE="file"

if [ $# -eq 1 ] 
then    
    FILE=$1
    echo "$FILE"
fi

while [ $SIZE -le '1000' ]
do
    touch "file_$SIZE"
    ./numgen $SIZE >> "${FILE}_$SIZE.txt"
    SIZE=`echo "$SIZE + $INCR" | bc`
done


