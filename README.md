# Light
Light is a build system intended to be an immediate representation of your build which can be much faster and has a translation layer that is best for connecting some flags to your other toolchains like tsc, clang, gcc, etc...
This is designed for build systems so that you can have flag abstraction and more control over how the wrapper or the compiler/interpreter acts without having to mess with flags manually.

# Features that is provided
- Abstracted translation layer, made for any universal flags that are frequent and are needed.
- No restrictions to one file, only .light and you can create many files!
- Both JIT and AOT compiling support depending on your needs for parsing.
And even if you don't feel like it's not enough then contribute to this project, it is open-source afterall!

# Light Compilation
Light is developed in C++ exclusively with no dependencies, you must be the one to compile to C++ code in order to have Light to read your parsed files.

# GCC source compilation
If you have GCC on msys2 or Linux Bash terminal, inside the terminal what you want to do is type these commands
```
git clone https://github.com/MidLevelGameDev/Light.git
# go into that Light Folder
./setup.sh
```
And then you have to make the binary availiable everywhere you go no matter what
```
sudo mv ./light /usr/bin # For Linux
```
or
```
vim ~/.bashrc # type "export PATH=$PATH:/c/whatever/your/Light/folder/is"
source ~/.bash # reset it to get this path
```

# For other compilations
If anyone want to make some documentation on how to compile Light for Clang, MSVS, or whatever, then go do it, or you can also make some binaries for people to use, if it is trusted enough I may add it to this file too as a link.
