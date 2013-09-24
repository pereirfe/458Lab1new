#!/bin/bash

if [ $# -ne 4 ] 
then
    echo 'Uso: bash tester $algo $tamanho $input $output'
    echo '$output = /dev/tty: STDOUT'

else 
    (time -p `./$1 $2 < $3` ) 2>&1 | grep user | cut -c 6- | tr -d '\n' >> $4
    echo -ne ";" >> $4
fi
