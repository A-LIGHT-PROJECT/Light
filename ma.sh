g++ -I Light_set -c Light_set/ligbus.cpp -o light.o
g++ -I Light_set -c Light_cmds/lightcmd.cpp -o lightcmd.o

g++ lightcmd.o light.o -o TestLight/light

g++ -I Light_set -c TestLight/parselight.cpp -o TestLight/parseit.o

g++ light.o TestLight/parseit.o -o ./TestLight/parseit

./TestLight/parseit

rm lightcmd.o light.o
