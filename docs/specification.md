# Bytecode Operation Specification
| Byte | Operation | Description |
| :---: | :---: | :---: |
| 0x00 | OP_NULL | Doesn't do anything... |
| 0x01 | OP_EXIT | Terminates the program. |
| 0x02 | OP_DEF_WRAPPER | Defines a wrapper and requires a string of the name or path to the compiler. |
| 0x03 | OP_STR_WRAP | A delimiter that represents the strings. |
| 0x04 | OP_SET_SETTER | Adds a flag to the wrapper, which includes a space at the beginning by default. (exp: -c) |
| 0x05 | OP_COPY | Copies a path or directories and recreates it. |
| 0x06 | OP_CREATE | Creates a file with zero text. |
| 0x07 | OP_CREATEDIR | Creates a new directory |
| 0x08 | OP_DEF | Adds your string to the wrapper, unlike OP_SET_SETTER, it doesn't add spaces in the beginning. |
