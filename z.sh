while [ 1 -eq 1 ]
do
    rm ___zshtmp
    touch ___zshtmp
    ps > ___zshtmp
    x=`cat ___zshtmp | wc -l`
    cat ___zshtmp

    sleep 3
    while [ "$x" -ne 0 ]
    do 
	echo -en "\b\r"
	x=`echo "$x - 1"| bc`
    done
    
done