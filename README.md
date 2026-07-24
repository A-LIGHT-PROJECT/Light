# Light
Light is a build system intended to be an immediate representation of your build which can be much faster and has a translation layer that is best for connecting some flags to your other toolchains like tsc, clang, gcc, etc...
This is designed for build systems so that you can have flag abstraction and more control over how the wrapper or the compiler/interpreter acts without having to mess with flags manually.

# Light Compilation
Light is developed in C++ exclusively with no dependencies, you must be the one to compile to C++ code in order to have Light to read your parsed files.

# GCC compilation
If you have GCC on msys2 or Linux Bash terminal, inside the terminal what you want to do is type these commands
```
git clone 
gcc ByteBuildSet.cpp Light.cpp -o light # or light.exe
```
