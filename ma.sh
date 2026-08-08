gcc -I Light_set -c Light_set/lightexe.c -o lightexe.o
g++ -I Light_set -c Light_set/ligbus.cpp -o light.o
g++ -I Light_set -c Light_cmds/lightcmd.cpp -o lightcmd.o

g++ lightcmd.o lightexe.o light.o -o TestLight/light

g++ -I Light_set -c TestLight/parselight.cpp -o TestLight/parseit.o

g++ lightexe.o light.o TestLight/parseit.o -o ./TestLight/parseit

./TestLight/parseit

rm lightcmd.o light.o lightexe.o
