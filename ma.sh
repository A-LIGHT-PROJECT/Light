
if [ "$1" == "compile" ]; then
	g++ -Wall -Wextra -Werror -I Light_set -c Light_cmds/lightcmd.cpp -o light26cmd.o

	gcc -Wall -Wextra -Werror -I Light_set -c Light_set/light26.c -o light26.o

	gcc -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c -o light26exec.o

	read -n 1 -p "safe_check [Y]: " SafeCheck
	echo
	if [ "$SafeCheck" != "Y" ]; then
		exit 0
	fi

	g++ light26cmd.o light26.o light26exec.o -o TestLight/light26
	g++ TestLight/parselight.cpp -o TestLight/parseit

	rm light26cmd.o light26.o light26exec.o
else
	g++ -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_cmds/lightcmd.cpp
	gcc -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/light26.c
	gcc -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c
fi
