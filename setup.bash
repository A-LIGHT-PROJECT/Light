#!/bin/bash

echo "Welcome to Light setup!"

if [[ ! command -v g++ || ! command -v gcc ]]; then
  echo "[Setup] gcc isn't installed, cannot keep going forward until you install gcc..."
  echo "---Ways to install GCC---"
  echo "MSYS2 Windows: pacman -S gcc"
  echo "Arch: sudo pacman -S gcc"
  echo
  exit 1
fi

echo "---[WELCOME TO LIGHT SETUP]---"
wait 1

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
	read -p "are you sure?[Y/n] " sure
	if [[ $sure != "Y" ]]; then
		echo "exiting setup.bash..."
		exit 0
	fi
elif [[ $OPSYS == "windows" ]]; then
	echo "--[WINDOWS setup]--"
	
fi
