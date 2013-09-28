
rm -f "BETTERQUICK_SAII.csv"
x=1
while read p
do
    if [ $x -gt 10 ]
    then
	x=1
	echo "" >> "BETTERQUICK_SAII.csv"
    fi

    (time -p `echo "$p" | ./quick` ) 2>&1 | grep user | cut -c 6- | tr -d '\n' >> "BETTERQUICK_SAII.csv"
    echo -ne ";" >> "BETTERQUICK_SAII.csv"

    x=`echo "$x + 1" | bc`
done < ALEABETTERQUICK.txt
