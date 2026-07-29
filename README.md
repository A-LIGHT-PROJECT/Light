# Light
Light is a build system intended to be an immediate representation of your build which can be much faster and has a translation layer that is best for connecting some flags to your other toolchains like tsc, clang, gcc, etc...
This is designed for build systems so that you can have flag abstraction and more control over how the wrapper or the compiler/interpreter acts without having to mess with flags manually.

# Goals of Light
- Have more features to make building much faster.
- Have a Immediate representation build system that is sufficent enough that it can be controlled the way we want.
- Have a build system that support JIT/AOT compilation.
- Have an abstraction layer that translate flags for you depending on your wrapper executable.

# Non-goals of Light
- Have people write Light directly in Bytecode all day, all night.
- Have a full fledged programming language.
- Being focused on other aspects other than building your projects.

# Executing Light files with a Virtual machine
Any .light file can be ran using the light command, like this
```
light your/path/to/yourname.light
```
You'll have to execute the file name using light in the beginning and the file path at the end, it is a very simple process.
You can get help by using
```
infolight --help
```


# Light Compilation
Light is developed in C++ exclusively with no dependencies, you must be the one to compile to C++ code in order to have Light to read your parsed files.
Light is available in many of the UNIX based operating systems:
- Windows through MSYS2 terminal and Cygwin
- MacOS
- Linux
- OpenBSD along with it's friends

# GCC source compilation
If you have GCC on msys2 or Linux Bash terminal, inside the terminal what you want to do is type these commands
```
curl https://raw.githubusercontent.com/MidLevelGameDev/Light/refs/heads/main/setup.bash
bash ./setup.bash
```
And follow the instructions on the setup
