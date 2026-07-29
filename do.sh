#!/bin/bash

echo "git commit [a] go to repo [s]"
echo
read -n 1 -p "command: " userinput
echo

if [[ $userinput == "a" ]]; then
	read -p "Message: " gitmsg
	git add . && git commit -m $gitmsg
	git push origin main
elif [[ $userinput == "s" ]]; then
	chromium github.com/midlevelgamedev/light &> /dev/null &
fi
