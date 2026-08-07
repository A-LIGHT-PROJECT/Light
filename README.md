# Light
Light is a build system intended to be made for speedy AOT compilation and have control over what files gets checked.

# Goals of Light
- Make Light best made for big codebases that handles Assembly, C/C++, etc...
- Make Light be as fast as possible at runtime for building...
- Make building much more easier

# Light be your build system!
More information on this soon, releasing late August

# Light Language
This build system has a language that can be similar to assembly.
```
.make:
  construction_strings "gcc thisprogram.c -o thisprogram"
  push
  execute
  pop
```
In order to compile this, you'll do
```
light "main.light"
```
This will compile and execute your IR binary to Light IR.
You can execute this again using the same command but it will be much faster.

In order to recompile in the command line, you can do
```
light --make "main.light"
```
This will recompile your Light binaries however this will not execute your .light file so you may have to do the same light command execution again.

# Light bytecode
This build system compiles to bytecode that has a very minimal amount of OP_CODES that is ran by a virtual machine. Since most of the verbose thinking is done by the parser, this bytecode will execute much faster at runtime than before!
You don't need to learn how to use it as the main Light language does it for you anyways.
