#!/bin/sh

i=0

if [ $# -ne 6 ] 
then
    echo 'Uso: bash executer $algo $step $end $times $input $output'
else
    alg=$1
    p=$2
    top=$3
    tot=$4
    inp=$5
    out=$6

    rm -f $out

    while [ $i -ne $tot ] 
    do
	x=$p
	while [ $x -ne $top ]
	do
	    `bash tester2.sh $alg $x $inp $out`
	    echo "Im at $x x $i"
	    x=`echo "$x + $p" | bc` 
	done
	i=`echo "$i + 1" | bc` 
	echo "" >> $out
    done
fi