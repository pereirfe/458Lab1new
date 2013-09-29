#!/bin/bash

SIZE=10000
INCR=10000
FILE="file"

if [ $# -ne 2 ] 
then    
    echo 'Uso: bash genvect $FILE $MODE'
    ./numgen 2>&1 | sed -n '2,30p' #gambiarra
else
    rm -f "$1"
    FILE=$1
    MODE=$2
    while [ $SIZE -le '500000' ]
    do
	echo -n "$SIZE" >> "$FILE"
	./numgen $SIZE $MODE >> "$FILE" && sleep 1
	SIZE=`echo "$SIZE + $INCR" | bc`
    done
fi