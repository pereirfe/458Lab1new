
rm -f "QUICK_SA.csv"
x=1
while read p
do
    if [ $x -gt 50 ]
    then
	x=1
	echo "" >> "QUICK_SA.csv"
    fi

    (time -p `echo "$p" | ./quick` ) 2>&1 | grep user | cut -c 6- | tr -d '\n' >> "QUICK_SA.csv"
    echo -ne ";" >> "QUICK_SA.csv"

    x=`echo "$x + 1" | bc`
done < ALEAQUICK.txt
