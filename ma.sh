
if [ "$1" == "compile" ]; then
	g++ -Wall -Wextra -Werror -I Light_set -c Light_cmds/lightcmd.cpp -o light26cmd.o

	gcc -Wall -Wextra -Werror -I Light_set -c Light_set/light26.c -o light26.o

	gcc -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c -o light26exec.o

	eval gcc -Wall -Wextra -Werror -I Light_set -c Light_set/viewlight26.c -o light26view.o $(pkg-config --cflags sdl3)

	read -n 1 -p "safe_check [Y]: " SafeCheck
	echo
	if [ "$SafeCheck" != "Y" ]; then
		exit 0
	fi

	eval g++ light26cmd.o light26.o light26exec.o light26view.o -o TestLight/light26 $(pkg-config --libs sdl3)
	g++ TestLight/parselight.cpp -o TestLight/parseit

	rm light26cmd.o light26.o light26exec.c light26view.o
elif [ "$1" == "windows" ]; then
	x86_64-w64-mingw32-g++ -g -Wall -Wextra -Werror -I Light_set -c Light_cmds/lightcmd.cpp -o light26cmdwin.o
	x86_64-w64-mingw32-gcc -g -Wall -Wextra -Werror -I Light_set -c Light_set/light26.c -o light26win.o
	x86_64-w64-mingw32-gcc -g -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c -o execlight26win.o

	read -n 1 -p "safe_check [Y]: " SafeCheck
	echo
	if [ "$SafeCheck" != "Y" ]; then
		exit 0
	fi

	x86_64-w64-mingw32-g++ light26cmdwin.o light26win.o execlight26win.o -o TestLight/light26_win32.exe -static -static-libgcc -static-libstdc++
	rm light26cmdwin.o light26win.o execlight26win.o
else
	g++ -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_cmds/lightcmd.cpp
	gcc -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/light26.c
	gcc -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c
	
	echo "Windows version: "

	x86_64-w64-mingw32-g++ -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_cmds/lightcmd.cpp
	x86_64-w64-mingw32-gcc -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/light26.c
	x86_64-w64-mingw32-gcc -fsyntax-only -g -Wall -Wextra -Werror -I Light_set -c Light_set/execlight26.c
fi
