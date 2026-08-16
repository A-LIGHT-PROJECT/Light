
if [ "$1" == "compile" ]; then
	g++ -Wall -Wextra -Werror -I Light_set -c Light_cmd/lightcmd.cpp -o light26cmd.o

	g++ -Wall -Wextra -Werror -I Light_set -c Light_set/light26.cpp -o light26.o

	gcc -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c -o light26exec.o

	read -n 1 -p "safe_check [Y]: " SafeCheck
	if [ "$SafeCheck" != "Y" ]; then
		exit 0
	fi

	g++ light26cmd.o light26.o light26exec.o -o TestLight/light26

	rm light26cmd.o light26.o light26exec.o
else
	g++ -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_cmds/lightcmd.cpp
	g++ -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/light26.cpp
	gcc -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c
fi
