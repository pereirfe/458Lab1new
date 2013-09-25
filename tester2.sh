#!/bin/bash

if [ $# -ne 4 ] 
then
    echo 'Uso: bash tester $algo $tamanho $input $output'
    echo '$output = /dev/tty: STDOUT'

else 
    x=`echo "$2 / 20" | bc` 
    y=`echo "$x + 1" | bc`
    sed -n "${y}q;${x},${x}p" < "$3" > ___tmp
    (time -p `./$1 < ___tmp` ) 2>&1 | grep user | cut -c 6- | tr -d '\n' >> $4
    ./$1 < ___tmp
    echo -ne ";" >> $4
#    rm -f ___tmp
fi
