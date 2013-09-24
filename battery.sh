#!/bin/bash

i=0

#while [ $i -ne 30 ]
#do 
 #   ./numgen 1000000 a >> 30kk.txt
  #  echo "AT $i"
   # i=`echo "$i + 1" | bc`
#done

./numgen 100000 a > 100k.txt

#bash executer.sh merge 2000 100000 3 100k.txt 0913merge_100k.csv

bash executer.sh quick 20000 1000000 3 100k.txt 0916quick_10_ak.csv

#bash executer.sh bubble 2000 100000 3 100k_r.txt 0913bubble_100k_r.csv

#bash executer.sh insertion 2000 100000 3 100k_r.txt 0913insertion_100k_r.csv

