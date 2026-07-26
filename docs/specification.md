# Contribution
You can always contribute to this project to add more operations and extra features!
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
| 0x09 | OP_PUSH | Pushes all the wrappers in a process of execution, this is made for safety and asynchronous control |
| 0x0A | OP_NOTIFY | Notifies externally and changes something if an error or condition was triggered, made for JIT compilation |
| 0x0B | OP_END | Acts as the one ending a certain part that is restricted, like a delimiter. |
| 0x0C | OP_SET | Sets up a automation system that does a check on files or does JIT compilation. |
| 0x0D | OP_IF | An if condition where a certain section gets restricted if this is false |

# Bytecode Flag Specification
| Byte 1 | Byte 2 | Flag | Description |
| :---: | :---: | :---: | :---: |
| 0x00 | 0x00 | SE_NOFLAG | It outputs no flag... |
| 0x00 | 0x01 | SE_SOURCE | Example: -c in GCC |
| 0x00 | 0x02 | SE_VERSION | Example: -std=c in GCC |
| 0x00 | 0x04 | SE_VERBOSE | Example: -v in GCC |
| 0x00 | 0x05 | SE_QUIET | Example: -quiet in GCC |
