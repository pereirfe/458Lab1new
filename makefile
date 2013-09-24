all: heaps quicks merges bubbles insertion timer verify numgen

heaps: heap.c sort.h
	gcc heap.c sort.h -o heap

quicks: quick.c sort.h
	gcc quick.c sort.h -o quick

merges:	merge.c sort.h 
	gcc merge.c sort.h -o merge

bubbles: bubble.c sort.h
	gcc bubble.c sort.h -o bubble

insertions: insertion.c sort.h
	gcc insertion.c sort.h -o insertion

timer: timer.cpp
	g++ timer.cpp -o timer

verify: verify.c
	gcc verify.c -o verify

numgen: numgen.c
	gcc numgen.c -o numgen

clean:
	rm -f numgen verify timer insertion bubble merge quick heap