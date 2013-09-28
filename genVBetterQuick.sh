
INCR=20
x=20
make
rm -f ALEABETTERQUICK.txt
while [ $x -ne '1000' ]
do
    bash vectmpc.sh 10 $x a >> ALEABETTERQUICK.txt
    x=`echo "$x + $INCR" | bc`
done





