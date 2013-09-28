
make

./betterquick < Aleatorios.txt >__tbqshtmp
cat __tbqshtmp | ./verify 20
cat __tbqshtmp

rm -f __tbqshtmp