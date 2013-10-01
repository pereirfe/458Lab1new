FILE="BETTERQUICK_M.csv"
rm -f "$FILE"
x=1
while read p
do
    if [ $x -gt 100 ]
    then
	x=1
	echo "" >> "$FILE"
    fi

    (time -p `echo "$p" | ./betterquick` ) 2>&1 | grep user | cut -c 6- | tr -d '\n' >> "$FILE"
    echo -ne ";" >> "$FILE"

    x=`echo "$x + 1" | bc`
done < QUICK_M.txt