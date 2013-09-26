#!/bin/bash

SIZE=20
INCR=20
FILE="file"

if [ $# -ne 2 ] 
then    
    echo 'Uso: bash genvect $FILE $MODE'
    ./numgen 2>&1 | sed -n '2,30p' #gambiarra
else
    rm -f "$1"
    FILE=$1
    MODE=$2
    while [ $SIZE -le '1000' ]
    do
	echo -n "$SIZE" >> "$FILE"
	./numgen $SIZE $MODE >> "$FILE"
	SIZE=`echo "$SIZE + $INCR" | bc`
    done
fi