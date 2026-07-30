#!/bin/bash

echo "Welcome to Light setup!"

if ! command -v g++; then
  echo "[Setup] gcc isn't installed, cannot keep going forward until you install gcc..."
  echo "---Ways to install GCC---"
  echo "MSYS2 Windows: pacman -S mingw-w64-ucrt-x86_64-gcc"
  echo "Arch Bash: sudo pacman -S gcc"
  echo
  exit 1
fi

echo "---[WELCOME TO LIGHT SETUP]---"
sleep 1

echo "[0/1] Checking operating system..."
case "$OSTYPE" in
	linux*) OPSYS="linux" ;;
	darwin*) OPSYS="macos" ;;
	msys*) OPSYS="windows" ;;
	cygwin*) OPSYS="windows" ;;
	*) OPSYS="UNKNOWN" && echo "Cannot find what specifically $OSTYPE is..." && exit 1 ;;
esac

echo "[1/1] $OPSYS FOUND"

if [[ "$OPSYS" == "linux" || "$OPSYS" == "macos" ]]; then
	echo "--[UNIX setup]--"
	cat<<'EOF'
== List of binaries ==
~ light (LIGBUS 1)
	* The interpreter itself.
~ lightinfo (LIGBUS 1)
	* Give information about light.
	* Can be the disassembler too.
EOF
# == Extras ==
# ~ light.hpp / light.cpp
# 	* this is the main and raw .light file with OP_CODES, needed if you want to make a parser of Light.
# EOF
# 	read -p "options: [A]ll [S]pecifically [N]one" extrasinput
	if ! command -v curl; then
		echo "[Setup] curl isn't installed, cannot keep going forward until you install curl..."
		echo
		exit 1
	fi
	read -p "are you sure?[Y/n] " sure
	if [[ $sure != "Y" ]]; then
		echo "exiting setup.bash..."
		exit 0
	fi
	echo "[Setup] setting up light and lightinfo binaries..."
	if [ -d ./templightfolder ]; then
		rm -rf ./templightfolder
	fi
	mkdir ./templightfolder
	cd ./templightfolder
	
	curl -O https://raw.githubusercontent.com/MidLevelGameDev/Light/refs/heads/main/Light_set/Light.hpp	
	curl -O https://raw.githubusercontent.com/MidLevelGameDev/Light/refs/heads/main/Light_set/Light.cpp

	curl -O https://raw.githubusercontent.com/MidLevelGameDev/Light/refs/heads/main/Light_cmds/lightcmd.cpp
	curl -O https://raw.githubusercontent.com/MidLevelGameDev/Light/refs/heads/main/Light_cmds/lightinfo.cpp

	cd ..
	
	tempPATH="./templightfolder"
	g++ -I $tempPATH -c ${tempPATH}/Light.cpp -o ${tempPATH}/LightMod.o
	g++ -I $tempPATH -c ${tempPATH}/lightcmd.cpp -o ${tempPATH}/light.o
	g++ -I $tempPATH -c ${tempPATH}/lightinfo.cpp -o ${tempPATH}/lightinfo.o

	ModObject="${tempPATH}/LightMod.o"
	Cmdo1="${tempPATH}/light.o"
	Cmdo2="${tempPATH}/lightinfo.o"

	g++ $ModObject $Cmdo1 -o ./light
	g++ $ModObject $Cmdo2 -o ./lightinfo

	rm -rf $tempPATH
	
	if [ -d ./light_exe ]; then
		rm -rf ./light_exe
	fi
	if [ -d /usr/bin ]; then
		sudo mv ./light /usr/bin
		sudo mv ./lightinfo /usr/bin
	elif [ -d /usr/local/bin ]; then
		sudo mv ./light /usr/local/bin
		sudo mv ./lightinfo /usr/local/bin
	else
		echo "[setup] failed to put in local binaries folder..."
		rm ./light
		rm ./lightinfo
		exit 1
	fi
	
	echo "[setup] Finished compiling binaries..."
	echo

	lightinfo --version
elif [[ $OPSYS == "windows" ]]; then
	echo "--[WINDOWS setup]--"
	
fi
