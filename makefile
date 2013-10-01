all: heaps quicks bquicks merges bubbles insertion timer verify numgen bettermerges

heaps: heap.c
	gcc heap.c -o heap

quicks: quick.c
	gcc quick.c -o quick

bquicks: betterquick.c
	gcc betterquick.c -o betterquick

bettermerges:	bettermerge.c 
	gcc bettermerge.c -o bettermerge

merges:	merge.c
	gcc merge.c -o merge

bubbles: bubble.c
	gcc bubble.c -o bubble

insertions: insertion.c
	gcc insertion.c -o insertion

timer: timer.cpp
	g++ timer.cpp -o timer

verify: verify.c
	gcc verify.c -o verify

numgen: numgen.c
	gcc numgen.c -o numgen

clean:
	rm -f numgen verify timer insertion bubble merge quick heap bquicks bettermerges