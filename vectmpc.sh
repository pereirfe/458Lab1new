#!/bin/bash

if [ $# -ne 3 ] 
then    
    echo 'Uso: bash vectmcpc $QT $SIZE $MODE'
    ./numgen 2>&1 | sed -n '2,30p'
else
    QT=$1
    while [ $QT -gt 0 ]
    do
	echo -n "$2"
	./numgen $2 $3 && sleep 1
	QT=`echo "$QT - 1" | bc`
    done
fi