#!/bin/bash

echo "Welcome to Light setup!"

if ! command -v g++; then
  echo "[Setup] gcc isn't installed, cannot keep going forward until you install gcc..."
  echo "---Ways to install GCC---"
  echo "MSYS2 Windows: pacman -S gcc"
  echo "Arch: sudo pacman -S gcc"
  echo
  exit 1
fi
if ! command -v git; then
	echo "[Setup] git isn't installed, cannot keep going forward until you install git..."
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
	read -p "are you sure?[Y/n] " sure
	if [[ $sure != "Y" ]]; then
		echo "exiting setup.bash..."
		exit 0
	fi
	if [ -d ./.templightfolder ]; then
		rm -rf ./.templightfolder
	fi
	mkdir ./.templightfolder

	rm -rf ./.templightfolder
	

elif [[ $OPSYS == "windows" ]]; then
	echo "--[WINDOWS setup]--"
	
fi
