# Light
Light is an installer intended to be made for cross-compatiablity with building your C, C++, Assembly, and Rust projects!

# Goals of Light
- Make a cross-compatiable build system that doesn't run exclusively for Linux or Windows!
- Reduce dependency overhead using pure standard libraries in C!
- Make building and installing much more faster when running these files without parser overhead!
- Have a visually appealing installation for all users using light!

This immediate representation was made so developers and users can run executables as quickly as possible while being greeted with a friendly interface!

# Following guidelines for languages
There is some guidelines that are meant to show you how to use light, light will have its different versions and backwards compatability will be a concern to people when it affects them.
Each version may have their own guidelines and may have outdated guidelines not used by a current version.
Check out PARSER_GUIDELINES.md for more information!

# Light Builder

You can run .light files using
```
light26 file.light
```
Specific version numbers will be at the end of each version released, such as light26 or light27
This is specifically for backwards compatability with other build systems.

# Light bytecode
This build system compiles to bytecode that has a very minimal amount of OP_CODES that is ran by a virtual machine. Since most of the verbose thinking is done by the parser, this bytecode will execute much faster at runtime than before!
You don't need to learn how to use it as the main Light language does it for you anyways.
