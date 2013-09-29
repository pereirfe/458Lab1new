FILE="BIGQUICKIII.csv"
rm -f "$FILE"
x=1
while read p
do
    if [ $x -gt 100 ]
    then
	x=1
	echo "" >> "$FILE"
    fi

    echo "$p" | ./quick
    #echo "$p"
    (time -p `echo "$p" | ./quick` ) 2>&1 | grep user | cut -c 6- | tr -d '\n' >> "$FILE"
    echo -ne ";" >> "$FILE"

    x=`echo "$x + 1" | bc`
done < BIGQUICK.txt