
make

./quick < Aleatorios.txt >__tqshtmp
cat __tqshtmp | ./verify 20
cat __tqshtmp

rm -f __tqshtmp